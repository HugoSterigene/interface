
#include "lux_thread.h"
#include <QThread>
#include <QTextEdit>
#include "logger.h"
#include <iostream>

lux_thread::lux_thread(QLCDNumber *lcd)
{
    this->lcd = lcd;

    l = new logger();

    /*this->lux.setPortName("COM30");

    this->lux.setBaudRate(QSerialPort::Baud9600);
    this->lux.setDataBits(QSerialPort::Data8);
    this->lux.setParity(QSerialPort::NoParity);
    this->lux.setStopBits(QSerialPort::OneStop);*/
}

void lux_thread::run()
{
    float value;
    QByteArray data;
    //bool err,logged = false;

    while(this->stop_flag)
    {

    }

    /*if(!lux.open(QIODevice::ReadOnly))
    {
        this->l->write_error("couldn't connect to luxmeter");
    }

    while(this->stop_flag)
    {
        data = this->lux.readAll();
        value = data.toFloat(&err);
        if(err)
        {
            this->lcd->display(test++);
        }
        else
        {
            if(logged == false)
            {
                this->l->write_error("couldn't retrieve the value from luxmeter");
                logged = true;
            }
        }

    }*/
}

void lux_thread::end()
{
    lux.close();
    this->stop_flag = false;
}
