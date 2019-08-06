#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
}

Worker::~Worker()
{
}
//将来放在子线程中执行的槽函数
void Worker::dowork(void){
    while(1){
        qDebug() << "子线程:" <<
            QThread::currentThreadId();
        QThread::sleep(1);
    }
}
