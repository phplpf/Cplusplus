#include "download.h"
#include "mainwindow.h"

Download::Download(const QUrl& url):fileUrl(url){
    //根据URL获取文件名
    QFileInfo fileInfo = fileUrl.path();
    QString filename = fileInfo.fileName();

    //设置要下载文件的路径
    QDir dir = QDir::home();
    //判断是否存在Download目录
    if(dir.exists("Downloads")==false){
        //如果该目录不存在则创建
        if(dir.mkdir("Downloads") == false){
            qDebug("创建目录失败");
            return;
        }
    }
    //指定下载文件放到主目录的Download下面
    QString path = QDir::homePath() + "/Downloads/"+ filename;
    //在本地创建同名的文件
    file = new QFile(path);
    //以写的方式打开文件
    file->open(QIODevice::WriteOnly);
}
Download::~Download()
{
    //qDebug() << "~Download";
}
//接收文件的槽函数
void Download::Download::ReceiveFile()
{
    if(reply->bytesAvailable()){
        file->write(reply->readAll());
    }
}
//参数:已收到数据的字节数/总字节数
void Download::onDownloadProgress(
        qint64 readBytes,qint64 totalBytes)
{
    qint64 progress=readBytes*100/totalBytes;//百分比
    qDebug() << file->fileName() << ":" << progress << "%....";
}
//接收文件完成的槽函数
void Download::Download::ReceiveFileFinished()
{
    qDebug() << file->fileName() << "文件下载完成";
    file->flush();//刷新文件流
    file->close();//关闭文件
    delete file;//销毁文件对象
    reply->deleteLater();//销毁响应对象
    emit downloadFinished();//发送信号，表示文件下载完成
}







