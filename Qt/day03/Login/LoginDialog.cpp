#include "LoginDialog.h"
#include <QDebug>
//构造函数
LoginDialog::LoginDialog(void){
    //界面初始化
    setupUi(this);
    //信号和槽连接
    //点击"Ok"按钮发送信号:accepted
    connect(m_btnBox,SIGNAL(accepted(void)),
            this,SLOT(onAccepted(void)));
    //点击"Cancel"按钮发送信号:rejected
    connect(m_btnBox,SIGNAL(rejected(void)),
            this,SLOT(onRejected(void)));
}
//处理Ok按钮的槽函数
void LoginDialog::onAccepted(void){
    //如果输入:tarena/123456则打印提示登录
    //成功,否则弹出消息框提示失败.
    if(m_editUsername->text()=="tarena" &&
        m_editPassword->text()=="123456"){
        qDebug("登录成功!");
        qDebug() << "Login Success!";
        close();//关闭登录窗口
    }
    else{
    //参数:图标,标题,提示文本,按钮,父窗口
        QMessageBox msgBox(
            QMessageBox::Critical,
            "Error",
            "用户名或密码错误!",
            QMessageBox::Ok,
            this);
        //显示消息提示框,并进入事件循环
        msgBox.exec();
    }
}
//处理cancel按钮的槽函数
void LoginDialog::onRejected(void){
    //消息提示框:提示用户是否真的退出登录
    QMessageBox msgBox(
        QMessageBox::Question,
        "登录",
        "确定要退出登录吗?",
        QMessageBox::No|QMessageBox::Yes,
        this);
    //显示消息提示框,并进入事件循环,点击上面
    //Yes或者No按钮都会退出事件循环,但是返回
    //结果不同,如果是Yes则关闭登录框.
    if(msgBox.exec()==QMessageBox::Yes){
        close();
    }
}










