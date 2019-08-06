#include "threaddialog.h"
#include "ui_threaddialog.h"

ThreadDialog::ThreadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreadDialog)
{
    ui->setupUi(this);
    qDebug() << "主线程:" <<
              QThread::currentThreadId();
    //点击按钮发送信号clicked,触发子线程执行
    //run函数将在子线程中被执行
    connect(ui->pushButton,SIGNAL(clicked()),
            &workerThread,SLOT(start()));
}

ThreadDialog::~ThreadDialog()
{
    delete ui;
}


