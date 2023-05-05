#ifndef PROFIL_H
#define PROFIL_H

#include <QDialog>
#include "logger.h"
#include "luxmeter.h"
#include "admin_main.h"

namespace Ui {
class profil;
}

class profil : public QDialog
{
    Q_OBJECT

public:
    explicit profil(QWidget *parent = nullptr);
    ~profil();
    void loginClicked();
    void resetValue();
    void setupCombo();

private:
    Ui::profil *ui;
    std::string username;
    std::string password;
    logger *loggings;
    LuxMeter *l;
    admin_main *a;
};

#endif // PROFIL_H
