#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击菜单栏(menuBar),发送信号triggered
    //参数:QAction表示某个具体菜单选项
    connect(ui->menuBar,SIGNAL(
                triggered(QAction*)),
            this,SLOT(onTriggered(QAction*)));
    //向工具栏添加工具按钮:Full,Normal
    ui->mainToolBar->addAction("Full");
    ui->mainToolBar->addAction("Normal");
    //点击工具栏按钮时,发送信号actionTriggered
    connect(ui->mainToolBar,SIGNAL(
                actionTriggered(QAction*)),
            this,SLOT(onTriggered(QAction*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTriggered(QAction* action)
{
    //在状态栏显示菜单选项文本内容
    ui->statusBar->showMessage(action->text());
    //点击Full全屏,Normal恢复
    if(action->text() == "Full"){
        showFullScreen();
    }
    else if(action->text() == "Normal"){
        showNormal();
    }
}







