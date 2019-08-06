#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog login;
    //exec():显示子窗口,并进入事件循环
    if(login.exec()==QDialog::Accepted){
        MainWindow w;
        w.show();
        return a.exec();
    }
}




