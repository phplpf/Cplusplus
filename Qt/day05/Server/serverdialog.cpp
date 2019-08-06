#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
    //当客户端向服务器发送连接请求时,发送信号newConnection
    connect(&tcpServer,SIGNAL(newConnection()),
            this,SLOT(onNewConnection()));
    //定时器到时发送信号:timeout
    connect(&timer,SIGNAL(timeout()),
            this,SLOT(onTimeout()));
}
ServerDialog::~ServerDialog()
{
    delete ui;
}
//创建服务器按钮对应的槽函数
void ServerDialog::on_createButton_clicked()
{
    //获取服务器端口
    serverPort = ui->portEdit->text().toShort();
    //设置监听服务器的IP和端口
    if(tcpServer.listen(QHostAddress::Any,serverPort)){
        qDebug() << "服务器创建成功!";
        //禁用创建按钮
        ui->createButton->setEnabled(false);
        //禁用端口输入
        ui->portEdit->setEnabled(false);
        //开始定时器
        timer.start(3000);
    }
    else{
        qDebug() << "服务器创建失败!";
    }

}
//响应客户端连接请求的槽函数
void ServerDialog::onNewConnection()
{
    //获取和客户端通信的套接字
    QTcpSocket* ClientSocket =
            tcpServer.nextPendingConnection();
    //保存套接字到容器
    tcpClientList.append(ClientSocket);
    //当套接字有消息到来时,发送信号:readyRead
    connect(ClientSocket,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
}
//接收聊天消息的槽函数
void ServerDialog::onReadyRead()
{
    //遍历检查哪个客户端有消息到来
    for(int i=0;i<tcpClientList.size();i++){
        //bytesAvailable():获取套接字等待读取消息的字节数
        //如果结果大于0,说明有消息,等于0说明没有消息.
        if(tcpClientList.at(i)->bytesAvailable()){
           //读取消息并保存
           QByteArray buf =
                tcpClientList.at(i)->readAll();
           //显示(保存)消息
           ui->listWidget->addItem(buf);
           ui->listWidget->scrollToBottom();
           //转发消息
           sendMessage(buf);
        }
    }
}
//转发聊天消息给其它客户端
void ServerDialog::sendMessage(
        const QByteArray& msg){
    for(int i=0;i<tcpClientList.size();i++){
        tcpClientList.at(i)->write(msg);
    }
}

//定时器到时后执行的槽函数
void ServerDialog::onTimeout(void){
    //遍历容器
    for(int i=0;i<tcpClientList.size();i++){
        //检查容器中的套接字是否已经断开连接
        if(tcpClientList.at(i)->state() ==
            QAbstractSocket::UnconnectedState){
            //将套接字从容器删除
            tcpClientList.removeAt(i);
            --i;
        }
    }
}





