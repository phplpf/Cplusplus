#include "TimeDialog.h"
//构造函数
TimeDialog::TimeDialog(void){
    //界面初始化
    setupUi(this);
    //信号和槽函数
    connect(m_button,SIGNAL(clicked(void)),
            this,SLOT(getTime(void)));
}
//自定义获取系统时间的槽函数
void TimeDialog::getTime(void){
    //获取当前时间
    QTime time = QTime::currentTime();
    //将时间转换为字符串形式
    QString str = time.toString("hh:mm:ss");
    //将字符串形式时间显示到label
    m_label->setText(str);
}



