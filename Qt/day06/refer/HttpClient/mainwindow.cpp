#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "download.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建管理通信的manager对象
    manager = new QNetworkAccessManager(this);
    //初始化请求网址
    request.setUrl(QUrl("http://code.tarena.com.cn/"));
    //向服务器发送请求
    sendRequest();
    //点击界面的链接时,发送信号anchorClicked,
    //参数表示点击链接的URL地址
    connect(ui->textBrowser,SIGNAL(anchorClicked(QUrl)),
        this,SLOT(onAnchorClicked(QUrl)));
}
MainWindow::~MainWindow()
{
    delete ui;
}

//向服务器发送请求
void MainWindow::sendRequest()
{
    //发送请求时,禁用界面,避免连续发送请求而导致的异常结束
    ui->textBrowser->setEnabled(false);
    //向服务器发送请求
    reply = manager->get(request);
    //如果服务器需要进行登录认证,manager会发送认证
    //信号:authenticationRequired
    connect(manager,SIGNAL(
        authenticationRequired(
            QNetworkReply*,QAuthenticator*)),
        this,SLOT(onAuthenticationRequired(
            QNetworkReply*,QAuthenticator*)));
    //如果认证成功,响应数据到来,发送信号readyRead
    connect(reply,SIGNAL(readyRead()),
        this,SLOT(onReadyRead()));
    //响应数据接收结束,发送信号finished
    connect(reply,SIGNAL(finished()),
        this,SLOT(onFinished()));
}
//处理登录认证的槽函数
void MainWindow::onAuthenticationRequired(
        QNetworkReply*,QAuthenticator* authenticator)
{
    //qDebug("onAuthenticationRequired");
    //从登录认证子窗口中,获取用户名和密码在进行认证
    LoginDialog login(this);
    //显示登录窗口,并进入事件循环,点击上面Ok/Cancel
    //时都会退出登录窗口,但是返回值不同.
    //如果点击Ok按钮退出,返回QDialog::Accepted
    if(login.exec() == QDialog::Accepted){
        authenticator->setUser(login.getUsername());
        authenticator->setPassword(login.getPassword());
    }
}
//接收响应数据的槽函数
void MainWindow::onReadyRead()
{
    //qDebug("onReadyRead");
    //读取响应数据,并保存
    buf += reply->readAll();
    //保存当前URl地址
    currentUrl = reply->url();
}
//接收响应数据完成时执行的槽函数
void MainWindow::onFinished()
{
    //qDebug("onFinished");
    //显示响应数据
    ui->textBrowser->setText(buf);
    //清空buf
    buf.clear();
    //销毁reply对象
    reply->deleteLater();
    //恢复界面
    ui->textBrowser->setEnabled(true);
}

//处理目录链接的槽函数
void MainWindow::onAnchorClicked(
        const QUrl &url){
    //qDebug()<<"当前的URL:"<<currentUrl.toString();
    //qDebug()<<"点击的URL:"<<url.toString();

    QUrl newUrl;
    //如果点击是不是"../",新的URL=当前URL+点击URL
    if(url.toString() != "../"){
        newUrl = currentUrl.toString() +
                    url.toString();
    }
    //如果点击是"../"
    else{
        //如果当前在首页,什么也不做
        if(currentUrl.toString() ==
            "http://code.tarena.com.cn/"){
            return;
        }
        //如果不再首页,去掉最后一级链接路径
        //查找目录路径中倒数第二次出现"/"位置
        int pos = currentUrl.toString(
                    ).lastIndexOf("/",-2);
        //字符串截断,去掉后面的路径
        newUrl =
            currentUrl.toString().mid(0,pos+1);
    }
    //判断点击URL如果不是目录则执行文件下载操作.
    if(url.toString().lastIndexOf("/")==-1){
        downloadFile(newUrl);
        return;
    }
    //设置新的请求URL
    request.setUrl(newUrl);
    //发送新的请求
    sendRequest();
}

//下载文件
void MainWindow::downloadFile(const QUrl& fileUrl)
{
    //创建下载文件线程
    QThread *thread = new QThread;
    //创建下载文件对象
    Download* download = new Download(fileUrl);
    //将下载文件对象移动到子线程中
    download->moveToThread(thread);
    //下载文件完成时，让线程退出
    connect(download,SIGNAL(downloadFinished()),
            thread,SLOT(quit()));
    //线程结束时，删除下载文件的对象
    connect(thread,SIGNAL(finished()),
            download,SLOT(deleteLater()));
    //线程结束时，删除线程对象
    connect(thread,SIGNAL(finished()),
            thread,SLOT(deleteLater()));
    //设置下载文件请求的URL
    download->request.setUrl(fileUrl);

    //发送获取下载文件的请求
    download->reply = manager->get(download->request);

    //响应数据到来，在子线程中完成下载操作
    //download已经移动到子线程中，通过信号触发里面槽将在子线程中运行
    connect(download->reply,SIGNAL(readyRead()),
            download,SLOT(ReceiveFile()));
    connect(download->reply,SIGNAL(finished()),
            download,SLOT(ReceiveFileFinished()));
    connect(download->reply,SIGNAL(downloadProgress(qint64,qint64)),
            download,SLOT(onDownloadProgress(qint64,qint64)));
    //开启子线程
    thread->start();
}






