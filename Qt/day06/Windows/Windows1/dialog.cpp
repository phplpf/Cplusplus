#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
//ok
void Dialog::on_buttonBox_accepted()
{
    if("验证成功"){
        accept();//退出登录窗口,返回QDialog::Accepted
    }
}
//Cancel
void Dialog::on_buttonBox_rejected()
{
    reject();//退出登录窗口,返回QDialog::Rejected
}



