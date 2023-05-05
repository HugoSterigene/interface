#include "profil.h"
#include "admin_main.h"
#include "ui_profil.h"
#include "logger.h"
#include "user_profils.h"
#include "qscreen.h"
#include <filesystem>
#include <QMainWindow>

profil::profil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profil),username(),password()
{

    ui->setupUi(this);
    // the LineEdit element will be set to hide the characters
    ui->passwordText->setEchoMode(QLineEdit::Password);

    setupCombo();

    // Setting the window size to the screen size
    QScreen *screen = QApplication::primaryScreen();
    QRect window_size = screen->geometry();
    int height = window_size.height();
    int width = window_size.width();

    QSize *screen_size = new QSize(width,height);

    this->resize(*screen_size);

    // initialisation of the logger
    this->loggings = new logger();
    // Sync. different button with their actions
    connect(ui->login,&QPushButton::clicked,this, &profil::loginClicked);

}

profil::~profil()
{
    delete ui;
}

void profil::setupCombo()
{
    std::string filepath = "./profil/";
    std::string file;

    for(const auto & entry : std::filesystem::directory_iterator(filepath))
    {
        if(entry.path().extension() == ".csv")
        {
            file = entry.path().stem().string();
            ui->usernameCombo->addItem(QString::fromStdString(file));
        }
    }
}

/**
 * @brief profil::loginClicked
 * The function called when the login button is pressed
 */
void profil::loginClicked()
{
    // getting and setting the username and the password
    QString username = ui->usernameCombo->currentText();
    QString password = ui->passwordText->text();
    this->username = username.toStdString();
    this->password = password.toStdString();
    // logging the fact that this user tried to connect
    std::string log;
    std::string stat_check;
    log.append(this->username);
    log.append(" trying to connect ");
    this->loggings->write_logging(log);
    log = "";

    // creating an object user_profile with the username and password
    user_profils *profil = new user_profils(this->username,this->password);
    // getting the status of the profil (connected or not)
    int connection = profil->open_profil();
    // different possible cases for the connection
    switch(connection)
    {
        // The profil does not exist logging an error
    case 1 :
        log.append(this->username);
        log.append(" does not exist ");
        this->loggings->write_error(log);
        break;
        // The profil exist but the wrong password was typed
    case 2 :
        log.append(this->username);
        log.append(" incorrect password entered ");
        this->loggings->write_error(log);
        break;
        // The profil exist and the user successfully connect to it
    case 0:
        log.append(this->username);
        log.append(" loging successful ");
        this->loggings->write_logging(log);
        // opening the luxmeter window (temporary)
        stat_check = profil->getStatus();
        if(stat_check == "admin")
        {
            a = new admin_main(this);
            a->show();
        }
        else if(stat_check == "user")
        {
            l = new LuxMeter(this);
            l->show();
        }

        resetValue();
        this->hide();
        break;
        // in case of any problem a default case will log an error
    default :
        this->loggings->write_error(" error while trying to open profil ");
        break;

    }
}


void profil::resetValue()
{
    this->username = "";
    this->password = "";
    ui->passwordText->clearFocus();
    ui->usernameCombo->clear();
    ui->passwordText->clear();
}

