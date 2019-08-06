#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QAuthenticator>//验证登录
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QUrl>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //向服务器发送请求
    void sendRequest();
private slots:
    //验证登录的槽函数
    void onAuthenticationRequired(
        QNetworkReply*,QAuthenticator*);
    //接收响应数据的槽函数
    void onReadyRead(void);
    //接收响应数据结束执行的槽函数
    void onFinished(void);

    //处理目录连接的槽函数
    void onAnchorClicked(const QUrl&);

private:
    //下载文件操作函数
    void downloadFile(const QUrl&);
private slots:
    //接收文件数据的槽函数
    void receiveFile();
    //显示文件下载进度的槽函数
    void onDownloadProgress(qint64,qint64);
    //接收文件数据结束的槽函数
    void receiveFileFinished();
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* manager;//管理通信
    QNetworkRequest request;//请求
    QNetworkReply* reply;//响应
    QByteArray buf;//保存响应数据
    QUrl currentUrl;//记录当前的URl地址
    QFile* file;//保存下载的文件
};

#endif // MAINWINDOW_H





