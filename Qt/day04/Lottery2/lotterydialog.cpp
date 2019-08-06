#include "lotterydialog.h"
#include "ui_lotterydialog.h"
#include <QTime>

LotteryDialog::LotteryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LotteryDialog)
{
    ui->setupUi(this);
    m_index = 0;
    //设置随机数种子
    qsrand(QTime::currentTime().msec());
    //初始化摇奖状态：未开始摇奖
    isStarted = false;
    //从“photos”目录下加载图片到容器
    loadPhotos("./photos");
    qDebug() << "加载到的图片个数：" <<
                m_vecPhotos.size();
    //定时器到时发送信号：timeout()
    connect(&m_timer,SIGNAL(timeout()),
            this,SLOT(onTimeout()));
}

LotteryDialog::~LotteryDialog()
{
    delete ui;
}
//和开始按钮匹配的槽函数
void LotteryDialog::on_m_button_clicked()
{
    if(isStarted == false){
        isStarted = true;//开始摇奖
        ui->m_button->setText("停止");
        //开始定时器，每隔50毫秒切换一个图片
        //m_timer = startTimer(50);
        m_timer.start(50);
    }
    else{
        isStarted = false;//停止摇奖
        ui->m_button->setText("开始");
        //关闭定时器
        //killTimer(m_timer);
        m_timer.stop();
    }
}
//从path路径中加载图片对象到容器
void LotteryDialog::loadPhotos(
        const QString& path)
{
    QDir dir(path);
    //遍历当前目录下所有图片
    QStringList l1=dir.entryList(QDir::Files);
    for(int i=0;i<l1.size();i++){
        //根据文件名创建图片对象
        QImage image(path+"/"+l1.at(i));
        //保存图片到容器
        m_vecPhotos << image;
    }
    //递归遍历子目录中所有图片
    QStringList l2=dir.entryList(
        QDir::Dirs|QDir::NoDotAndDotDot);
    for(int i=0;i<l2.size();i++){
        loadPhotos(path+"/"+l2.at(i));
    }
}
//定时器事件处理函数
/*void LotteryDialog::timerEvent(QTimerEvent *)
{
    //随机获取一个图片索引
    m_index = qrand() % m_vecPhotos.size();
    //触发绘图事件
    update();
}*/
//定时器到时以后要执行的槽函数
void LotteryDialog::onTimeout(){
    //随机获取一个图片索引
    m_index = qrand() % m_vecPhotos.size();
    //触发绘图事件
    update();
}
//绘图事件处理函数
void LotteryDialog::paintEvent(QPaintEvent *)
{
    //创建画家对象
    QPainter painter(this);
    //获取绘图所在矩形区域
    QRect rect = ui->m_frame->frameRect();
    //坐标平移：让rect和painter使用相同坐标系
    rect.translate(ui->m_frame->pos());
    //将m_index对应的图片画到rect矩形区域中
    painter.drawImage(rect,m_vecPhotos[m_index]);
}







