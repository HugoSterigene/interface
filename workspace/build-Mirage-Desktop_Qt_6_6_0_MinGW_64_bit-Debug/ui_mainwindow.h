/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mirage
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mirage)
    {
        if (Mirage->objectName().isEmpty())
            Mirage->setObjectName("Mirage");
        Mirage->resize(633, 468);
        centralwidget = new QWidget(Mirage);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_3 = new QSpacerItem(259, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 187, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(264, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(259, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");
        connectButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(connectButton, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(259, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 186, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(259, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(169, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        Mirage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mirage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 633, 20));
        Mirage->setMenuBar(menubar);
        statusbar = new QStatusBar(Mirage);
        statusbar->setObjectName("statusbar");
        Mirage->setStatusBar(statusbar);

        retranslateUi(Mirage);

        QMetaObject::connectSlotsByName(Mirage);
    } // setupUi

    void retranslateUi(QMainWindow *Mirage)
    {
        Mirage->setWindowTitle(QCoreApplication::translate("Mirage", "MainWindow", nullptr));
        connectButton->setText(QCoreApplication::translate("Mirage", "Se connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mirage: public Ui_Mirage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
