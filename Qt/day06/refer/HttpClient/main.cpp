#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //qDebug() << "main:" << QThread::currentThreadId();
    return a.exec();
}
