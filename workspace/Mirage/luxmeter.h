#ifndef LUXMETER_H
#define LUXMETER_H

#include <QDialog>
#include <QSerialPort>
#include <QTimeEdit>
#include <QTimer>
#include "logger.h"
#include "lux_thread.h"

namespace Ui {
class LuxMeter;
}

class LuxMeter : public QDialog
{
    Q_OBJECT

public:
    explicit LuxMeter(QWidget *parent = nullptr);
    ~LuxMeter();
    void capture();
    void capture_timer();
    void save_capture(std::string file);
    void com_Lux();
    void disconnect();

public slots:
    void slotTimer();


private:
    Ui::LuxMeter *ui;
    logger *l;
    QTimer timer;
    std::string filepath;
    int duration;
    int intervalle;
    lux_thread *thread;

};

#endif // LUXMETER_H
