#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <QDialog>
#include "logger.h"
#include <QButtonGroup>

namespace Ui {
class admin_main;
}

class admin_main : public QDialog
{
    Q_OBJECT

public:
    explicit admin_main(QWidget *parent = nullptr);
    ~admin_main();
    void createClicked();
    void disconnect();

private:
    Ui::admin_main *ui;
    std::string username;
    std::string password;
    std::string status;
    logger *loggings;
    QButtonGroup *buttonGroup;
};

#endif // ADMIN_MAIN_H
