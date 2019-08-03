#ifndef SHOWIMAGEDIALOG_H
#define SHOWIMAGEDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QDebug>

namespace Ui {
class ShowImageDialog;
}

class ShowImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowImageDialog(QWidget *parent = 0);
    ~ShowImageDialog();
private:
    //绘图事件处理函数
    void paintEvent(QPaintEvent *);
private slots:
    //上一张按钮匹配的槽函数
    void onPrevImage(void);
    //下一张按钮匹配的槽函数
    void onNextImage(void);
private:
    Ui::ShowImageDialog *ui;
    int m_index;//图片索引
};

#endif // SHOWIMAGEDIALOG_H
