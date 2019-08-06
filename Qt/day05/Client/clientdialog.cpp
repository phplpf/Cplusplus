#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    status = false;//初始化离线状态
    //和服务器连接成功时,发送信号:connected
    connect(&tcpSocket,SIGNAL(connected()),
            this,SLOT(onConnected()));
    //和服务器断开连接时,发送信号:disconnected
    connect(&tcpSocket,SIGNAL(disconnected()),
            this,SLOT(onDisconnected()));
    //收到聊天消息时,发送信号:readyRead()
    connect(&tcpSocket,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
    //网络异常发送信号:error
    connect(&tcpSocket,SIGNAL(error(
            QAbstractSocket::SocketError)),
            this,SLOT(onError()));
}

ClientDialog::~ClientDialog()
{
    delete ui;
}
//发送按钮对应的槽函数
void ClientDialog::on_sendButton_clicked()
{
    //获取消息
    QString msg=ui->messageEdit->text();
    if(msg==""){
        return;
    }
    msg = username + ":" + msg;
    //发送消息
    tcpSocket.write(msg.toUtf8());
    //清空消息输入框
    ui->messageEdit->clear();
}
//连接服务器按钮对应的槽函数
void ClientDialog::on_connectButton_clicked()
{
    //如果是离线状态则建立和服务器连接
    if(status == false){
        //通过界面获取服务器IP
        QString ip = ui->serverIpEdit->text();
        if(serverIp.setAddress(ip)==false){
            QMessageBox::critical(
                this,"Error","IP地址格式错误");
            return;
        }
        //通过界面获取服务器的端口
        serverPort =
          ui->serverPortEdit->text().toShort();
        if(serverPort<1024){
            QMessageBox::critical(
                this,"Error","端口号错误");
            return;
        }
        //通过界面获取聊天室昵称
        username = ui->usernameEdit->text();
        if(username == ""){
            QMessageBox::critical(
                this,"Error","昵称不能为空");
            return;
        }
        //向服务器发送连接请求:
        //如果连接成功发送信号:connected
        //如果连接失败发送信号:error
        tcpSocket.connectToHost(
                serverIp,serverPort);

    }
    //如果当前是在线状态则断开连接
    else{
        //发送离开聊天室提示消息
        QString msg = username+":离开了聊天室";
        tcpSocket.write(msg.toUtf8());
        //断开连接,发送信号:disconnected
        tcpSocket.disconnectFromHost();
    }

}
//和服务器连接成功时执行的槽函数
void ClientDialog::onConnected(void)
{
    qDebug() << "连接服务器成功!";
    status = true;//标记客户端在线
    //恢复"发送"消息按钮为可点击状态
    ui->sendButton->setEnabled(true);
    //修改连接服务器按钮文本:"离开聊天室"
    ui->connectButton->setText("离开聊天室");
    //禁用:ip\port\username输入
    ui->serverIpEdit->setEnabled(false);
    ui->serverPortEdit->setEnabled(false);
    ui->usernameEdit->setEnabled(false);
    //向服务器发送进入聊天室的提示消息
    QString msg = username + ":进入了聊天室";
    //toUtf8:QString转换为QByteArray
    tcpSocket.write(msg.toUtf8());
}
//和服务器断开连接时执行的槽函数
void ClientDialog::onDisconnected(void)
{
    status = false;//标记客户端离线
    //禁用"发送"消息按钮
    ui->sendButton->setEnabled(false);
    //修改离开聊天室按钮文本:"连接服务器"
    ui->connectButton->setText("连接服务器");
    //恢复:ip\port\username输入
    ui->serverIpEdit->setEnabled(true);
    ui->serverPortEdit->setEnabled(true);
    ui->usernameEdit->setEnabled(true);
}
//接收聊天消息的槽函数
void ClientDialog::onReadyRead(void)
{
    if(tcpSocket.bytesAvailable()){
        //接收消息并保存
        QByteArray buf = tcpSocket.readAll();
        //显示聊天消息
        ui->listWidget->addItem(buf);
        ui->listWidget->scrollToBottom();
    }
}
//网络异常时执行的槽函数
void ClientDialog::onError(void)
{
    //errorString:获取网络异常原因的字符串
    QMessageBox::critical(
        this,"Error",tcpSocket.errorString());
}






