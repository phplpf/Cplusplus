#ifndef __TIMEDIALOG_H
#define __TIMEDIALOG_H
#include "ui_TimeDialog.h"
#include <QTime>
//使用组合方法复用和界面相关代码
class TimeDialog:public QDialog{
    Q_OBJECT
public:
    //构造函数
    TimeDialog(void);
public slots:
    //自定义获取系统时间的槽函数
    void getTime(void);
private:
    //将来通过"ui->"访问界面相关代码
    Ui::TimeDialog* ui;
};

#endif//__TIMEDIALOG_H




