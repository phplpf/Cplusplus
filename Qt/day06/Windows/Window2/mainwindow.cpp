#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
/*
    Dialog dialog(this);
    //显示子窗口,并进入事件循环(这时主界面无法响应)
    dialog.exec();
*/
    //显示子窗口,不响应主界面
    Dialog* pdialog = new Dialog(this);
    pdialog->show();

}




