#include "luxmeter.h"
#include "ui_luxmeter.h"
#include "logger.h"
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <QTimer>
#include <chrono>
#include <QSerialPort>
#include "qscreen.h"
#include "lux_thread.h"


LuxMeter::LuxMeter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LuxMeter)
{
    // automatic setup of the ui
    ui->setupUi(this);

    ui->lcdLuxmeter->setDigitCount(12);

    // Part to resize the widget at the size of the screen
    QScreen *screen = QApplication::primaryScreen();
    QRect window_size = screen->geometry();
    int height = window_size.height();
    int width = window_size.width();

    QSize *screen_size = new QSize(width,height);

    this->resize(*screen_size);

    // initialisating the logger
    l = new logger();

    // intialisation of the thread to get informations from the luxmeter
    this->thread = new lux_thread(ui->lcdLuxmeter);

    connect(this->thread, &lux_thread::finished,this->thread,&lux_thread::deleteLater);
    connect(ui->disconnectButton, &QPushButton::clicked,this,&LuxMeter::disconnect);

    thread->start();


    // Sync. the action with button in charge of the one click capture for the luxmeter values
    connect(ui->inst_capture,&QPushButton::clicked,this, &LuxMeter::capture);
    // Sync. tha action with button in charge of the capture in time of the luxmeter values
    connect(ui->timerButton,&QPushButton::clicked,this, &LuxMeter::capture_timer);



    // Sync. the timeout action of the timer with the slot function
    QObject::connect(&timer, SIGNAL(timeout()),this, SLOT(slotTimer()));



}

LuxMeter::~LuxMeter()
{
    delete ui;
}

void LuxMeter::disconnect()
{
    this->thread->end();
    this->parentWidget()->show();
    this->close();

}


/**
 * @brief LuxMeter::slotTimer
 * Slot function to execute by the timer when he times out
 */
void LuxMeter::slotTimer()
{
    ///
    /// The timer act not as you may think, here a quick explaination :
    /// after every period of time ( = one intervalle) the timer will execute an action
    /// we changed this action in the 'main' function of the class
    /// now the timer will run as long as the program is running
    /// so to stop the timer after a certain amount of time we decrement the time left by the intervalle time
    /// when the duration reach 0 it will be the last iteration of the timer
    ///
    this->duration -= this->intervalle;
    if(this->duration < 0)
    {
        // We stop the timer and log it
        this->l->write_logging("luxmeter mesurement cycle ended");
        this->timer.stop();
    }
    else
    {
        // we save the luxmeter value
        save_capture(this->filepath);
    }

}

/**
 * @brief LuxMeter::capture
 * Function called when instant capture button is clicked
 */
void LuxMeter::capture()
{
    // creating the filepath to save the value
    this->filepath = "";
    // getting the time and date to name the file
    std::string time = this->l->getCurrentTime();
    this->filepath = "./capture/" + time + ".csv";
    l->write_logging("capturing luxmeter values");
    // saving the value using the filepath created
    save_capture(this->filepath);

}

/**
 * @brief LuxMeter::capture_timer
 * Function called when the timed capture button is clicked
 */
void LuxMeter::capture_timer()
{
    // getting and setting the values of the intervalle and the duration of the capture
    this->intervalle = ui->inter_capture->value();
    this->duration = ui->inter_capture_2->value();

    // creating the filepath to save the values
    this->filepath = "";
    // getting the time and date to name the file
    std::string time = this->l->getCurrentTime();
    this->filepath = "./capture/" + time + ".csv";
    l->write_logging("capturing luxmeter values for " + std::to_string(this->duration) + " secondes");

    // setting the timer with the intervalle * 1000 (because we want the intervalle in millisecond
    timer.setInterval((this->intervalle)*1000);
    // if this setting is true, the timer will act only once after the intervalle
    timer.setSingleShot(false);
    // Starting the timer
    timer.start();
}

/**
 * @brief LuxMeter::save_capture
 * This function will save in a given file the actual value of the luxmeter
 * @param f : the file we will save the value in
 */
void LuxMeter::save_capture(std::string f)
{

    std::ofstream file;
    // getting the current time and date
    std::string time = this->l->getCurrentTime();
    // getting the value of the luxmeter
    std::string value = std::to_string(ui->lcdLuxmeter->value());

    // we check if the file already exist
    struct stat buffer;
    if(stat (f.c_str(),&buffer) == 0)
    {
        // if it exist we open it with the appened condition
        file.open(f,std::ios::app);
        //if it didn't open we log an error
        if(!file.is_open())
        {
            this->l->write_error("Problem encountered : capture file didn't open properly");
        }
        // if it did open we write the value with the date/time in the file
        else
        {
            file << time << ',' << value << std::endl;
        }

    }
    //if the file doesn't exist we will create it
    else
    {
        // logging the creation of the file
        this->l->write_logging(f + " was created");
        file.open(f);
        if(!file.is_open())
        {
            this->l->write_error("Problem encountered : capture file wasn't created correctly");
        }
        file << time << ',' << value << std::endl;
    }

}
