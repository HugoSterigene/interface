#include "admin_main.h"
#include "ui_admin_main.h"
#include "qscreen.h"
#include "logger.h"
#include "user_profils.h"
#include <QButtonGroup>


admin_main::admin_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_main)
{
    ui->setupUi(this);

    // Setting the window size to the screen size
    QScreen *screen = QApplication::primaryScreen();
    QRect window_size = screen->geometry();
    int height = window_size.height();
    int width = window_size.width();

    QSize *screen_size = new QSize(width,height);

    this->resize(*screen_size);

    this->buttonGroup = new QButtonGroup(this);

    buttonGroup->addButton(ui->admin_radio);
    buttonGroup->addButton(ui->uti_radio);

    buttonGroup->setExclusive(true);

    loggings = new logger();

    connect(ui->createUser,&QPushButton::clicked,this,&admin_main::createClicked);
    connect(ui->disconnectButton, &QPushButton::clicked,this,&admin_main::disconnect);
}

admin_main::~admin_main()
{
    delete ui;
}

void admin_main::disconnect()
{
    this->parentWidget()->show();
    this->close();

}

/**
 * @brief admin_main::createClicked
 * Temporary function to create a user profil
 */
void admin_main::createClicked()
{
    // getting and setting the password and username
    QString username = ui->usernameText->text();
    QString password = ui->passwordText->text();
    this->username = username.toStdString();
    this->password = password.toStdString();
    std::string log;

    QAbstractButton *checked = buttonGroup->checkedButton();
    QRadioButton *checkedButton = dynamic_cast<QRadioButton*>(checked);

    QString buttonName = checkedButton->objectName();
    std::string name = buttonName.toStdString();
    if(name == "admin_radio")
    {
        this->status = "admin";
    }
    else if(name == "uti_radio")
    {
        this->status = "user";
    }
    // creating a profil object
    user_profils *profil = new user_profils(this->username,this->password);

    // creating the profil and getting the return code
    int creation = profil->create_profil(this->status);
    switch(creation)
    {
        // the profil already exist
    case -1:
        log.append(this->username);
        log.append(" already exist");
        this->loggings->write_error(log);
        break;
    case 0:
        // the profil was succesfully created
        log.append(this->username);
        log.append(" profil created");
        this->loggings->write_logging(log);
        break;
    default :
        this->loggings->write_error(" Error while creating user profil");
        break;

    }
}
