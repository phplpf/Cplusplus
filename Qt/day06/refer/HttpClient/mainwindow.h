#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QAuthenticator>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <download.h>

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
    //处理登录认证的槽函数
    void onAuthenticationRequired(
            QNetworkReply*,QAuthenticator*);
    //接收响应数据的槽函数
    void onReadyRead();
    //接收响应数据完成时执行的槽函数
    void onFinished();
    //处理目录链接的槽函数
    void onAnchorClicked(const QUrl& url);

private:
    //下载文件
    void downloadFile(const QUrl& fileUrl);

private:
    Ui::MainWindow *ui;
public:
    QNetworkAccessManager* manager;//管理通信
private:
    QNetworkRequest request;//请求
    QNetworkReply* reply;//响应
    QUrl currentUrl;//记录当前的Url地址
    QByteArray buf;//保存接收的响应数据
};

#endif // MAINWINDOW_H



