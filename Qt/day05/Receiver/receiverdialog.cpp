#include "receiverdialog.h"
#include "ui_receiverdialog.h"

ReceiverDialog::ReceiverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiverDialog)
{
    ui->setupUi(this);
    isStarted = false;
    udpSocket = new QUdpSocket(this);
}

ReceiverDialog::~ReceiverDialog()
{
    delete ui;
}
//开始接收按钮对应的槽函数
void ReceiverDialog::on_startButton_clicked()
{
    if(isStarted == false){
        isStarted = true;//开始接收
        ui->startButton->setText("停止接收");
        ui->portEdit->setEnabled(false);
        //获取端口
        port = ui->portEdit->text().toShort();
        //绑定IP(默认"0.0.0.0")和端口
        bool res = udpSocket->bind(port);
        if(res == false){
            qDebug() << "绑定失败!";
        }
        else{
            qDebug() << "绑定成功";
            //当收到广播消息,发送信号readyRead
            connect(udpSocket,SIGNAL(readyRead()),
                    this,SLOT(messageReceived()));
        }
    }
    else{
        isStarted = false;//停止接收
        ui->startButton->setText("开始接收");
        ui->portEdit->setEnabled(true);
        //关闭通信的套接字
        udpSocket->close();
    }
}
//接收广播消息的槽函数
void ReceiverDialog::messageReceived(void)
{
    //判断套接字是否右等待读取的数据包
    if(udpSocket->hasPendingDatagrams()){
        //准备接收消息的数据缓冲区
        QByteArray datagram;
        //设置缓冲区大小
        datagram.resize(
            //获取等待读取数据包的大小
            udpSocket->pendingDatagramSize());
        //接收广播消息
        //data():QByteArray转换char*
        udpSocket->readDatagram(
            datagram.data(),datagram.size());
        //显示消息到界面
        ui->listWidget->addItem(datagram);
        //回滚显示最底部的消息(最新的消息)
        ui->listWidget->scrollToBottom();
    }
}





