#include "mainwindow.h"
#include "qtsingleapplication.h"

#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
    QtSingleApplication a(argc, argv);
    if (a.sendMessage("")) {
        return 0;
    }
    MainWindow w;
    w.show();
    QObject::connect(&a, SIGNAL(messageReceived(const QString&)),&w, SLOT(handleMessage(const QString&)));
    return a.exec();
}
