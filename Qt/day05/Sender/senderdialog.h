#ifndef SENDERDIALOG_H
#define SENDERDIALOG_H

#include <QDialog>
#include <QUdpSocket>//QT += network
#include <QTimer>
#include <QDebug>

namespace Ui {
class SenderDialog;
}

class SenderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SenderDialog(QWidget *parent = 0);
    ~SenderDialog();

private slots:
    //开始按钮对应的槽函数
    void on_startButton_clicked();
    //定时发送广播消息的槽函数
    void sendMessage(void);
private:
    Ui::SenderDialog *ui;
    bool isStarted;//标记:开始广播/停止广播
    QUdpSocket* udpSocket;//udp套接字
    QTimer* timer;//定时器

};

#endif // SENDERDIALOG_H



