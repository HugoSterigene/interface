/********************************************************************************
** Form generated from reading UI file 'admin_main.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_MAIN_H
#define UI_ADMIN_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin_main
{
public:
    QWidget *logscreen;
    QLineEdit *usernameText;
    QLineEdit *passwordText;
    QPushButton *createUser;
    QRadioButton *uti_radio;
    QRadioButton *admin_radio;
    QPushButton *disconnectButton;

    void setupUi(QDialog *admin_main)
    {
        if (admin_main->objectName().isEmpty())
            admin_main->setObjectName("admin_main");
        admin_main->resize(635, 298);
        logscreen = new QWidget(admin_main);
        logscreen->setObjectName("logscreen");
        logscreen->setEnabled(true);
        logscreen->setGeometry(QRect(30, 30, 520, 171));
        usernameText = new QLineEdit(logscreen);
        usernameText->setObjectName("usernameText");
        usernameText->setGeometry(QRect(30, 40, 311, 31));
        passwordText = new QLineEdit(logscreen);
        passwordText->setObjectName("passwordText");
        passwordText->setGeometry(QRect(30, 80, 311, 31));
        createUser = new QPushButton(logscreen);
        createUser->setObjectName("createUser");
        createUser->setGeometry(QRect(390, 60, 80, 22));
        createUser->setMouseTracking(true);
        uti_radio = new QRadioButton(logscreen);
        uti_radio->setObjectName("uti_radio");
        uti_radio->setGeometry(QRect(30, 130, 83, 21));
        uti_radio->setChecked(true);
        admin_radio = new QRadioButton(logscreen);
        admin_radio->setObjectName("admin_radio");
        admin_radio->setGeometry(QRect(120, 130, 101, 21));
        disconnectButton = new QPushButton(admin_main);
        disconnectButton->setObjectName("disconnectButton");
        disconnectButton->setGeometry(QRect(410, 210, 120, 22));

        retranslateUi(admin_main);

        QMetaObject::connectSlotsByName(admin_main);
    } // setupUi

    void retranslateUi(QDialog *admin_main)
    {
        admin_main->setWindowTitle(QCoreApplication::translate("admin_main", "Dialog", nullptr));
        createUser->setText(QCoreApplication::translate("admin_main", "create", nullptr));
        uti_radio->setText(QCoreApplication::translate("admin_main", "utilisateur", nullptr));
        admin_radio->setText(QCoreApplication::translate("admin_main", "administrateur", nullptr));
        disconnectButton->setText(QCoreApplication::translate("admin_main", "d\303\251connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_main: public Ui_admin_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_MAIN_H
