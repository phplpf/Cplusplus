#ifndef THREADDIALOG_H
#define THREADDIALOG_H

#include <QDialog>
#include "workerthread.h"

namespace Ui {
class ThreadDialog;
}

class ThreadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThreadDialog(QWidget *parent = 0);
    ~ThreadDialog();

private:
    Ui::ThreadDialog *ui;
    WorkerThread workerThread;//子线程
};

#endif // THREADDIALOG_H
