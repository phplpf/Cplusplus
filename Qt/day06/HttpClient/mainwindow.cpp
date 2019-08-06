#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建管理通信的Manager对象
    manager = new QNetworkAccessManager(this);
    //初始化请求
    request.setUrl(
        QUrl("http://code.tarena.com.cn/"));
    //发送请求
    sendRequest();

    //点击界面"链接"时,发送信号anchorClicked
    connect(ui->textBrowser,
            SIGNAL(anchorClicked(QUrl)),
        this,SLOT(onAnchorClicked(QUrl)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//向服务器发送请求
void MainWindow::sendRequest()
{
    //发送请求,返回用于接收响应数据reply对象
    reply = manager->get(request);
    //如果服务器需要认证,Manager发送认证信号:
    //authenticationRequired
    connect(manager,SIGNAL(
        authenticationRequired(
            QNetworkReply*,QAuthenticator*)),
        this,SLOT(onAuthenticationRequired(
            QNetworkReply*,QAuthenticator*)));
    //响应数据到来,reply发送信号:readyread
    connect(reply,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
    //响应数据接收结束,reply发送信号:finished
    connect(reply,SIGNAL(finished()),
            this,SLOT(onFinished()));
}
//验证登录的槽函数
void MainWindow::onAuthenticationRequired(
    QNetworkReply*,QAuthenticator* a)
{
    //1）在验证登录增加登录对话框，
    //用户名和密码信息从登录对话框获取
    //qDebug("onAuthenticationRequired");
    a->setUser("tarenacode");
    a->setPassword("code_2013");
}
//接收响应数据的槽函数
void MainWindow::onReadyRead(void)
{
    //qDebug("onReadyRead");
    //接收数据并保存
    buf += reply->readAll();
    //保存当前Url地址
    currentUrl = reply->url();
}
//接收响应数据结束执行的槽函数
void MainWindow::onFinished(void)
{
    //qDebug("onFinished");
    //显示响应数据
    ui->textBrowser->setText(buf);
    //清空buf
    buf.clear();
    //销毁reply对象
    reply->deleteLater();
}
//处理目录连接的槽函数
//参数"url"表示点击链接的url地址
void MainWindow::onAnchorClicked(
        const QUrl& url){
    //http://code.tarena.com.cn/
    //qDebug() << "当前url:" << currentUrl;
    //CSDCode/
    //qDebug() << "点击url:" << url;
    //http://code.tarena.com.cn/CSDCode/

    //要进入的新链接Url地址
    QUrl newUrl;
    //如果点击链接不是"../"
    if(url.toString() != "../"){
        //newUrl=当前Url+点击Url
        newUrl = currentUrl.toString()
            + url.toString();
    }
    else{
        //如果当前在主界面,点击"../"什么也不做
        if(currentUrl.toString() ==
            "http://code.tarena.com.cn/"){
            return;
        }
        //如果不在主界面,去掉最后一级路径
        //http://code.tarena.com.cn/CSDCode/
        //http://code.tarena.com.cn/
        //查找倒数第二次出现位置"/"
        int pos = currentUrl.toString(
                    ).lastIndexOf("/",-2);
        //字符串截断,去掉最后一级路径
        newUrl = currentUrl.toString(
                    ).mid(0,pos+1);
    }
    //判断newUrl是不是文件链接,如果是文件链接,则执
    //行下载文件操作:
    if(url.toString().lastIndexOf("/")==-1){
        //qDebug("下载文件操作!");
        downloadFile(newUrl);
        return;
    }
    //设置请求为新的Url地址
    request.setUrl(newUrl);
    //发送新的请求
    sendRequest();

}
//下载文件操作函数
void MainWindow::downloadFile(
        const QUrl& fileUrl)
{
    //http://code.tarena.com.cn/xx/xx/xx.txt
    qDebug() << fileUrl;
    //根据fileUrl获取文件名
    QFileInfo fileInfo = fileUrl.path();
    QString filename = fileInfo.fileName();

    //在本地创建同名文件
    file = new QFile(filename,this);
    //以写的方式打开文件,如果不存在则创建
    file->open(QIODevice::WriteOnly);

    //设置下载文件请求
    request.setUrl(fileUrl);
    //发送下载文件的请求
    reply = manager->get(request);
    //响应数据到来(文件内容),发送信号readyRead
    connect(reply,SIGNAL(readyRead()),
            this,SLOT(receiveFile()));
    //伴随响应数据接收,发送表示下载进度
    //信号:downloadProgress
    //参数:已收到字节数/总字节数
    connect(reply,SIGNAL(
          downloadProgress(qint64,qint64)),
        this,SLOT(
          onDownloadProgress(qint64,qint64)));
    //响应数据接收完成(文件下载完成),发送信号finished
    connect(reply,SIGNAL(finished()),
        this,SLOT(receiveFileFinished()));
}
//接收文件数据的槽函数
void MainWindow::receiveFile()
{
    //读取响应数据并写入本地文件
    file->write(reply->readAll());
}
//显示文件下载进度的槽函数
void MainWindow::onDownloadProgress(
        qint64 bytesRead,qint64 bytesTotal)
{
    //计算下载进度的百分比
    int progress = bytesRead*100/bytesTotal;
    qDebug() << file->fileName() << ":"
             << progress << "%...";
}
//接收文件数据结束的槽函数
void MainWindow::receiveFileFinished()
{
    qDebug() << file->fileName() << "下载完成!";
    file->flush();//刷新文件流
    file->close();//关闭文件
    reply->deleteLater();//销毁响应对象
}







