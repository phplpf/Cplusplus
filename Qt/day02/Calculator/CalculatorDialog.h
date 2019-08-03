#ifndef __CALCULATORDIALOG_H
#define __CALCULATORDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QHBoxLayout>
//当前类继承父窗口类QDialog,当前类就是父窗口
class CalculatorDialog:public QDialog{
    Q_OBJECT//moc
public:
    //构造函数
    CalculatorDialog(void);
public slots:
    //恢复等号按钮状态的槽函数
    void enableButton(void);
    //计算和显示结果的槽函数
    void calcClicked(void);
private:
    QLineEdit* m_editX;//左操作数
    QLineEdit* m_editY;//右操作数
    QLineEdit* m_editZ;//显示结果
    QLabel* m_label;//"+"
    QPushButton* m_button;//"="
};

#endif//__CALCULATORDIALOG_H

