#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDialog(QWidget *parent = 0);
    ~ClientDialog();

private slots:
    //发送按钮对应的槽函数
    void on_sendButton_clicked();
    //连接服务器按钮对应的槽函数
    void on_connectButton_clicked();
    //和服务器连接成功时执行的槽函数
    void onConnected(void);
    //和服务器断开连接时执行的槽函数
    void onDisconnected(void);
    //接收聊天消息的槽函数
    void onReadyRead(void);
    //网络异常时执行的槽函数
    void onError(void);
private:
    Ui::ClientDialog *ui;
    bool status;//标记客户端状态:在线/离线
    QTcpSocket tcpSocket;//和服务器通信的tcp套接字
    QHostAddress serverIp;//服务器IP
    quint16 serverPort;//服务器port
    QString username;//聊天室昵称
};

#endif // CLIENTDIALOG_H


