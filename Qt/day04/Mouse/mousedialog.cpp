#include "mousedialog.h"
#include "ui_mousedialog.h"

MouseDialog::MouseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MouseDialog)
{
    ui->setupUi(this);
    m_drag = false;
}

MouseDialog::~MouseDialog()
{
    delete ui;
}
//鼠标按下执行的事件处理函数
void MouseDialog::mousePressEvent(
        QMouseEvent *event)
{
    //判断是否为鼠标左键
    if(event->button() == Qt::LeftButton){
        //获取label所在的矩形区域
        QRect rect = ui->label->frameRect();
        //坐标平移，让rect和鼠标使用相同坐标系
        rect.translate(ui->label->pos());
        //判断鼠标点击位置是否在rect矩形区域中
        if(rect.contains(event->pos())==true){
            m_drag = true;
            //相对位置=label位置-鼠标位置
            m_pos = ui->label->pos() -
                    event->pos();
        }
    }
}
//鼠标抬起执行的事件处理函数
void MouseDialog::mouseReleaseEvent(
        QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_drag = false;
    }
}
//鼠标移动执行的事件处理函数
void MouseDialog::mouseMoveEvent(
        QMouseEvent *event)
{
    if(m_drag == true){
        //计算label要移动的新位置
        QPoint newPos = event->pos() + m_pos;
        //限制label移动不能超出窗口
        QSize s1 = size();//窗口大小
        QSize s2 = ui->label->size();//label大小
        //x:0--窗口宽-label宽
        if(newPos.x() < 0){
            newPos.setX(0);
        }
        else if(newPos.x()>s1.width()-s2.width()){
            newPos.setX(s1.width()-s2.width());
        }
        //y:0--窗口高-label高
        if(newPos.y() < 0){
            newPos.setY(0);
        }
        else if(newPos.y()>s1.height()-s2.height()){
            newPos.setY(s1.height()-s2.height());
        }

        //移动label到新位置
        ui->label->move(newPos);
    }
}



