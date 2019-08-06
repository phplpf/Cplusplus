#ifndef Download_H
#define Download_H

#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <mainwindow.h>

class Download : public QObject
{
    Q_OBJECT
public:
    //构造函数，参数表示要下载的文件连接
    Download(const QUrl& url);
    ~Download();
private slots:
    //接收文件的槽函数
    void ReceiveFile();
    //更新显示文件下载进度的槽函数
    //参数:已收到数据的字节数/总字节数
    void onDownloadProgress(qint64,qint64);
    //接收文件完成的槽函数
    void ReceiveFileFinished();

signals:
    //自定义信号，文件下载完成时发送
    void downloadFinished();
private:
    QNetworkRequest request;//请求
    QNetworkReply* reply;//响应
    QUrl fileUrl;//下载文件的URL地址
    QFile* file;

    //将MainWindow类声明为当前类的友元，友元类可以访问当前类的任何成员
    friend class MainWindow;
};

#endif // Download_H
