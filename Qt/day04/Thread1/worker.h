#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    ~Worker();
signals:
public slots:
    //将来放在子线程中执行的槽函数
    void dowork(void);
};

#endif // WORKER_H
