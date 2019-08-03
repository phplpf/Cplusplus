#include "showimagedialog.h"
#include "ui_showimagedialog.h"

ShowImageDialog::ShowImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowImageDialog)
{
    ui->setupUi(this);
    //上一张
    connect(ui->m_btnPrev,SIGNAL(clicked()),
            this,SLOT(onPrevImage()));
    //下一张
    connect(ui->m_btnNext,SIGNAL(clicked()),
            this,SLOT(onNextImage()));

    m_index = 0;
}
ShowImageDialog::~ShowImageDialog()
{
    delete ui;
}
//绘图事件处理函数
void ShowImageDialog::paintEvent(QPaintEvent *)
{
    //qDebug() << "某个图像绘制";
    //1)创建"画家"对象
    QPainter painter(this);
    //2)获取绘图的所在矩形区域
    QRect rect = ui->m_frame->frameRect();

    //qDebug() << "rect:" << rect;
    //qDebug() << "frame:" << ui->m_frame->pos();
    //rect坐标平移,让其和painter使用相同坐标系
    rect.translate(ui->m_frame->pos());
    //qDebug() << "平移后rect:" << rect;
    //qDebug() << "平移后frame:" << ui->m_frame->pos();

    //3)构造要显示图片,":"表示相对资源路径
    QImage image(":/new/prefix1/images/" +
                 QString::number(m_index)+".jpg");
    //4)将image画到rect对应的矩形区域中
    painter.drawImage(rect,image);
}
//上一张按钮匹配的槽函数
void ShowImageDialog::onPrevImage(void)
{
    //qDebug() << "绘制前一个图片";
    if(--m_index < 0){
        m_index = 9;
    }
    update();//触发绘图事件
}
//下一张按钮匹配的槽函数
void ShowImageDialog::onNextImage(void)
{
    //qDebug() << "绘制后一个图片";
    if(++m_index > 9){
        m_index = 0;
    }
    update();//触发绘图事件
}



