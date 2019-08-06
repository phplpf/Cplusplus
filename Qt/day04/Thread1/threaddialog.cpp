#include "threaddialog.h"
#include "ui_threaddialog.h"

ThreadDialog::ThreadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreadDialog)
{
    ui->setupUi(this);
    qDebug() << "主线程:" <<
             QThread::currentThreadId();
    Worker* worker = new Worker;

    //将worker移动到子线程中
    worker->moveToThread(&workerThread);

    connect(ui->pushButton,SIGNAL(clicked()),
            worker,SLOT(dowork()));

    workerThread.start();
}

ThreadDialog::~ThreadDialog()
{
    delete ui;
}
