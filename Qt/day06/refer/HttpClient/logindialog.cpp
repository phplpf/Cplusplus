#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
//Ok按钮对应的槽函数
void LoginDialog::on_buttonBox_accepted()
{
    username = ui->usernameEdit->text();
    password = ui->passwordEdit->text();
    accept();//退出,返回QDialog::Accepted
}
//Cancel按钮对应的槽函数
void LoginDialog::on_buttonBox_rejected()
{
    reject();//退出,返回QDialog::Rejected
}
//获取用户名
const QString& LoginDialog::getUsername()
{
    return username;
}
//获取密码
const QString& LoginDialog::getPassword()
{
    return password;
}




