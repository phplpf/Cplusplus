#include "workerthread.h"

WorkerThread::WorkerThread()
{
}
WorkerThread::~WorkerThread()
{
}

//2)重新线程入口函数
void WorkerThread::run(void){
    while(1){
        qDebug() <<"子线程:"<<currentThreadId();
        sleep(1);
    }
}







