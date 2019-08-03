#ifndef __LOGINDIALOG_H
#define __LOGINDIALOG_H
#include "ui_LoginDialog.h"
#include <QMessageBox>//消息提示框

class LoginDialog:public QDialog{
    Q_OBJECT
public:
    //构造函数
    LoginDialog(void);
private slots:
    //处理Ok按钮的槽函数
    void onAccepted(void);
    //处理Cancel按钮的槽函数
    void onRejected(void);
private:
    Ui::LoginDialog* ui;
};
//练习:用组合方式,重构当前代码

#endif//__LOGINDIALOG_H



