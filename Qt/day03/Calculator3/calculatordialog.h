#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>

//#include "ui_CalculatorDialog.h"
namespace Ui {
class CalculatorDialog;//短视声明
}

class CalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorDialog(QWidget *parent = 0);
    ~CalculatorDialog();
public slots:
    void enableButton(void);
    void calcClicked(void);

private:
    //将来通过"ui->"访问和界面相关
    Ui::CalculatorDialog *ui;
};

#endif // CALCULATORDIALOG_H


