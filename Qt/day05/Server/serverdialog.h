#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

namespace Ui {
class ServerDialog;
}

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerDialog(QWidget *parent = 0);
    ~ServerDialog();

private slots:
    //创建服务器按钮对应的槽函数
    void on_createButton_clicked();
    //响应客户端连接请求的槽函数
    void onNewConnection();
    //接收聊天消息的槽函数
    void onReadyRead();
private:
    //转发聊天消息给其它客户端
    void sendMessage(const QByteArray& msg);
private slots:
    //定时器到时后执行的槽函数
    void onTimeout(void);
private:
    Ui::ServerDialog *ui;
    QTcpServer tcpServer;//tcp服务器
    quint16 serverPort;//服务器端口
    //保存和客户端通信的套接字
    QList<QTcpSocket*> tcpClientList;
    QTimer timer;//定时器
};

#endif // SERVERDIALOG_H



