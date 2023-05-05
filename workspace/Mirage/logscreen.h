
#ifndef LOGSCREEN_H
#define LOGSCREEN_H

#include <QWidget>
#include "logger.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Mirage; }
QT_END_NAMESPACE

class logscreen : public QMainWindow
{
    Q_OBJECT

public:
    logscreen(QWidget *parent = nullptr);
    ~logscreen();
    void loginClicked();
    void createClicked();

private:
    Ui::Mirage *ui;
    std::string username;
    std::string password;
    logger *loggings;
};


#endif // LOGSCREEN_H
