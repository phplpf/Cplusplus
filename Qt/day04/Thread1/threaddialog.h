#ifndef THREADDIALOG_H
#define THREADDIALOG_H

#include <QDialog>
#include "worker.h"

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
    QThread workerThread;
};

#endif // THREADDIALOG_H
