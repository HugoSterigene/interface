/********************************************************************************
** Form generated from reading UI file 'profil.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFIL_H
#define UI_PROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profil
{
public:
    QWidget *logscreen;
    QLineEdit *passwordText;
    QPushButton *login;
    QComboBox *usernameCombo;

    void setupUi(QDialog *profil)
    {
        if (profil->objectName().isEmpty())
            profil->setObjectName("profil");
        profil->resize(787, 431);
        profil->setMinimumSize(QSize(787, 0));
        logscreen = new QWidget(profil);
        logscreen->setObjectName("logscreen");
        logscreen->setEnabled(true);
        logscreen->setGeometry(QRect(100, 140, 520, 141));
        passwordText = new QLineEdit(logscreen);
        passwordText->setObjectName("passwordText");
        passwordText->setGeometry(QRect(30, 80, 311, 31));
        login = new QPushButton(logscreen);
        login->setObjectName("login");
        login->setGeometry(QRect(390, 60, 80, 22));
        login->setMouseTracking(true);
        usernameCombo = new QComboBox(logscreen);
        usernameCombo->setObjectName("usernameCombo");
        usernameCombo->setGeometry(QRect(30, 30, 311, 31));

        retranslateUi(profil);

        QMetaObject::connectSlotsByName(profil);
    } // setupUi

    void retranslateUi(QDialog *profil)
    {
        profil->setWindowTitle(QCoreApplication::translate("profil", "Dialog", nullptr));
        login->setText(QCoreApplication::translate("profil", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profil: public Ui_profil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFIL_H
