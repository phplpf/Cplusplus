#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    //Ok按钮对应的槽函数
    void on_buttonBox_accepted();
    //Cancel按钮对应的槽函数
    void on_buttonBox_rejected();
public:
    //获取用户名
    const QString& getUsername();
    //获取密码
    const QString& getPassword();
private:
    Ui::LoginDialog *ui;
    QString username;//保存用户名
    QString password;//保存密码
};

#endif // LOGINDIALOG_H


