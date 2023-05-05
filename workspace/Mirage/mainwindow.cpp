
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <time.h>
#include <unistd.h>
#include "qscreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mirage)
{
    ui->setupUi(this);
    // Resizing the window to match the screen size
    QScreen *screen = QApplication::primaryScreen();
    QRect window_size = screen->geometry();
    int height = window_size.height();
    int width = window_size.width();

    QSize *screen_size = new QSize(width,height);

    this->resize(*screen_size);

    // Sync. the connection button with the action
    connect(ui->connectButton,&QPushButton::clicked,this, &MainWindow::print_LogScreen);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::print_LogScreen
 * Function to open the profil screen
 */
void MainWindow::print_LogScreen()
{
    p = new profil(this);
    p->show();
    this->hide();

}

