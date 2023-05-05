
#ifndef LUX_THREAD_H
#define LUX_THREAD_H

#include <QThread>
#include <QTextEdit>
#include <QLCDNumber>
#include <QSerialPort>
#include "logger.h"



class lux_thread : public QThread
{
    Q_OBJECT
public:
    lux_thread(QLCDNumber *lcd);
    void run();
    void end();

signals:
    void finished();
private:
    QLCDNumber *lcd;
    logger *l;
    QSerialPort lux;
    bool stop_flag = true;
};


#endif // LUX_THREAD_H
