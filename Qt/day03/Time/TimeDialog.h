#ifndef __TIMEDIALOG_H
#define __TIMEDIALOG_H
#include "ui_TimeDialog.h"
#include <QTime>
//使用继承方法复用和界面相关代码
class TimeDialog:public QDialog,
                public Ui::TimeDialog{
    Q_OBJECT
public:
    //构造函数
    TimeDialog(void);
public slots:
    //自定义获取系统时间的槽函数
    void getTime(void);
};

#endif//__TIMEDIALOG_H

