#include "senderdialog.h"
#include "ui_senderdialog.h"

SenderDialog::SenderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SenderDialog)
{
    ui->setupUi(this);
    isStarted = false;//标记:未开始广播
    //创建UDP套接字
    udpSocket = new QUdpSocket(this);
    //创建定时器
    timer = new QTimer(this);
    //定时器到时发送信号timeout
    connect(timer,SIGNAL(timeout()),
            this,SLOT(sendMessage()));
}
SenderDialog::~SenderDialog()
{
    delete ui;
}
//开始按钮对应的槽函数
void SenderDialog::on_startButton_clicked()
{
    if(isStarted == false){
        isStarted = true;//开始广播
        //修改按钮文本:停止广播
        ui->startButton->setText("停止广播");
        //禁用广播消息输入,端口输入
        ui->messageEdit->setEnabled(false);
        ui->portEdit->setEnabled(false);
        //开始定时器,每隔1秒发送一次广播消息
        timer->start(1000);
    }
    else{
        isStarted = false;//停止广播
        ui->startButton->setText("开始广播");
        ui->messageEdit->setEnabled(true);
        ui->portEdit->setEnabled(true);
        //关闭定时器
        timer->stop();
    }
}
//定时发送广播消息的槽函数
void SenderDialog::sendMessage(void)
{
    //获取消息
    QString msg = ui->messageEdit->text();
    if(msg == ""){
        return;
    }
    //获取广播端口
    quint16 port =
        ui->portEdit->text().toShort();
    //发送广播广播
    //toUtf8():QString转换QByteArray
    udpSocket->writeDatagram(msg.toUtf8(),
            QHostAddress::Broadcast,port);

    qDebug() << "发送了消息:" << msg;
}





