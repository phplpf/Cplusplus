#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QDebug>

//1)继承QThread
class WorkerThread : public QThread
{
public:
    WorkerThread();
    ~WorkerThread();
    //2)重新线程入口函数
    void run(void);
};

#endif // WORKERTHREAD_H




