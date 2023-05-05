
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logger.h"
#include "profil.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Mirage; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void print_LogScreen();


private:
    Ui::Mirage *ui;
    logger *loggings;
    profil *p;

};

#endif // MAINWINDOW_H
