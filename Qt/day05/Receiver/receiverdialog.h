#ifndef RECEIVERDIALOG_H
#define RECEIVERDIALOG_H

#include <QDialog>
#include <QUdpSocket>
#include <QDebug>

namespace Ui {
class ReceiverDialog;
}

class ReceiverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiverDialog(QWidget *parent = 0);
    ~ReceiverDialog();

private slots:
    //开始接收按钮对应的槽函数
    void on_startButton_clicked();
    //接收广播消息的槽函数
    void messageReceived(void);
private:
    Ui::ReceiverDialog *ui;
    bool isStarted;//标记:开始接收/停止接收
    QUdpSocket* udpSocket;//udp套接字
    quint16 port;//接收消息端口
};

#endif // RECEIVERDIALOG_H



