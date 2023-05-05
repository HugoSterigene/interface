
#include "mainwindow.h"
#include "qscreen.h"

#include <QApplication>
#include <QtVirtualKeyboard>


int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QApplication a(argc, argv);

    MainWindow window;


    window.show();
    return a.exec();
}
