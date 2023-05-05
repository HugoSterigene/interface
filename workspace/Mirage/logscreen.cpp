
#include "logscreen.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include <string>
#include "user_profils.h"
#include <QWidget>

logscreen::logscreen(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Mirage),username(),password()
{
    ui->setupLogUi(this);

    this->loggings = new logger();

    connect(ui->login,&QPushButton::clicked,this, &logscreen::loginClicked);
    connect(ui->createUser,&QPushButton::clicked,this,&logscreen::createClicked);

}

logscreen::~logscreen()
{

}

void logscreen::loginClicked()
{
    QString username = ui->usernameText->text();
    QString password = ui->passwordText->text();
    this->username = username.toStdString();
    this->password = password.toStdString();
    std::string log;
    log.append(this->username);
    log.append(" trying to connect ");
    this->loggings->write_logging(log);
    log = "";

    user_profils *profil = new user_profils(this->username,this->password);
    int connection = profil->open_profil();
    switch(connection)
    {
    case 1 :
        log.append(this->username);
        log.append(" does not exist ");
        this->loggings->write_error(log);
        break;
    case 2 :
        log.append(this->username);
        log.append(" incorrect password entered ");
        this->loggings->write_error(log);
        break;
    case 0:
        log.append(this->username);
        log.append(" loging successful ");
        this->loggings->write_logging(log);
        break;
    default :
        this->loggings->write_error(" error while trying to open profil ");
        break;

    }
}

void logscreen::createClicked()
{
    QString username = ui->usernameText->text();
    QString password = ui->passwordText->text();
    this->username = username.toStdString();
    this->password = password.toStdString();
    std::string log;

    user_profils *profil = new user_profils(this->username,this->password);

    int creation = profil->create_profil();
    switch(creation)
    {
    case -1:
        log.append(this->username);
        log.append(" already exist");
        this->loggings->write_error(log);
        break;
    case 0:
        log.append(this->username);
        log.append(" profil created");
        this->loggings->write_logging(log);
        break;
    default :
        this->loggings->write_error(" Error while creating user profil");
        break;

    }
}


