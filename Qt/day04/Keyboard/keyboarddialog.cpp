#include "keyboarddialog.h"
#include "ui_keyboarddialog.h"

KeyboardDialog::KeyboardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyboardDialog)
{
    ui->setupUi(this);
}

KeyboardDialog::~KeyboardDialog()
{
    delete ui;
}
//按键按下时执行的事件处理函数
void KeyboardDialog::keyPressEvent(
        QKeyEvent* event){
    //获取label当前位置
    int x = ui->label->pos().x();
    int y = ui->label->pos().y();
    if(event->key() == Qt::Key_Up){//上
        ui->label->move(x,y-10);
    }
    else if(event->key() == Qt::Key_Down){//下
        ui->label->move(x,y+10);
    }
    else if(event->key() == Qt::Key_Left){//左
        ui->label->move(x-10,y);
    }
    else if(event->key() == Qt::Key_Right){//右
        ui->label->move(x+10,y);
    }

}





