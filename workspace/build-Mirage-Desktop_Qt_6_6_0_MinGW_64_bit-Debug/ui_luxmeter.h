/********************************************************************************
** Form generated from reading UI file 'luxmeter.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUXMETER_H
#define UI_LUXMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LuxMeter
{
public:
    QFrame *frame;
    QTabWidget *captureTab;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TimerLabel;
    QSpinBox *inter_capture_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout;
    QLabel *intervalleLabel;
    QSpinBox *inter_capture;
    QPushButton *timerButton;
    QWidget *tab_2;
    QPushButton *inst_capture;
    QFrame *frame_5;
    QGridLayout *gridLayout;
    QLabel *luxLabel;
    QPushButton *disconnectButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLCDNumber *lcdLuxmeter;

    void setupUi(QDialog *LuxMeter)
    {
        if (LuxMeter->objectName().isEmpty())
            LuxMeter->setObjectName("LuxMeter");
        LuxMeter->resize(753, 698);
        frame = new QFrame(LuxMeter);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(90, 130, 507, 417));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        captureTab = new QTabWidget(frame);
        captureTab->setObjectName("captureTab");
        captureTab->setGeometry(QRect(10, 10, 361, 221));
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_3 = new QFrame(tab);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        TimerLabel = new QLabel(frame_3);
        TimerLabel->setObjectName("TimerLabel");

        horizontalLayout_2->addWidget(TimerLabel);

        inter_capture_2 = new QSpinBox(frame_3);
        inter_capture_2->setObjectName("inter_capture_2");
        inter_capture_2->setMinimum(0);
        inter_capture_2->setMaximum(3600);
        inter_capture_2->setSingleStep(10);
        inter_capture_2->setValue(0);

        horizontalLayout_2->addWidget(inter_capture_2);


        verticalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(tab);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_4);
        horizontalLayout->setObjectName("horizontalLayout");
        intervalleLabel = new QLabel(frame_4);
        intervalleLabel->setObjectName("intervalleLabel");

        horizontalLayout->addWidget(intervalleLabel);

        inter_capture = new QSpinBox(frame_4);
        inter_capture->setObjectName("inter_capture");
        inter_capture->setMinimum(1);
        inter_capture->setMaximum(60);

        horizontalLayout->addWidget(inter_capture);


        verticalLayout_3->addWidget(frame_4);

        timerButton = new QPushButton(tab);
        timerButton->setObjectName("timerButton");

        verticalLayout_3->addWidget(timerButton);

        captureTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        inst_capture = new QPushButton(tab_2);
        inst_capture->setObjectName("inst_capture");
        inst_capture->setGeometry(QRect(50, 40, 80, 22));
        captureTab->addTab(tab_2, QString());
        frame_5 = new QFrame(LuxMeter);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(90, 20, 411, 91));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_5);
        gridLayout->setObjectName("gridLayout");
        luxLabel = new QLabel(frame_5);
        luxLabel->setObjectName("luxLabel");

        gridLayout->addWidget(luxLabel, 2, 0, 1, 1);

        disconnectButton = new QPushButton(frame_5);
        disconnectButton->setObjectName("disconnectButton");

        gridLayout->addWidget(disconnectButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        lcdLuxmeter = new QLCDNumber(frame_5);
        lcdLuxmeter->setObjectName("lcdLuxmeter");

        gridLayout->addWidget(lcdLuxmeter, 2, 2, 1, 2);


        retranslateUi(LuxMeter);

        captureTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LuxMeter);
    } // setupUi

    void retranslateUi(QDialog *LuxMeter)
    {
        LuxMeter->setWindowTitle(QCoreApplication::translate("LuxMeter", "Dialog", nullptr));
        TimerLabel->setText(QCoreApplication::translate("LuxMeter", "Temps de capture :(sec)", nullptr));
        intervalleLabel->setText(QCoreApplication::translate("LuxMeter", "Intervalle de capture :", nullptr));
        timerButton->setText(QCoreApplication::translate("LuxMeter", "capture", nullptr));
        captureTab->setTabText(captureTab->indexOf(tab), QCoreApplication::translate("LuxMeter", "timer", nullptr));
        inst_capture->setText(QCoreApplication::translate("LuxMeter", "capture", nullptr));
        captureTab->setTabText(captureTab->indexOf(tab_2), QCoreApplication::translate("LuxMeter", "instantan\303\251e", nullptr));
        luxLabel->setText(QCoreApplication::translate("LuxMeter", "valeur en Lux :", nullptr));
        disconnectButton->setText(QCoreApplication::translate("LuxMeter", "d\303\251connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LuxMeter: public Ui_LuxMeter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUXMETER_H
