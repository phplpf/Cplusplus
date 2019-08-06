#ifndef MOUSEDIALOG_H
#define MOUSEDIALOG_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class MouseDialog;
}

class MouseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MouseDialog(QWidget *parent = 0);
    ~MouseDialog();
    //鼠标按下执行的事件处理函数
    void mousePressEvent(QMouseEvent *);
    //鼠标抬起执行的事件处理函数
    void mouseReleaseEvent(QMouseEvent *);
    //鼠标移动执行的事件处理函数
    void mouseMoveEvent(QMouseEvent *);
private:
    Ui::MouseDialog *ui;
    bool m_drag;//拖拽比较，选中label则移动
    QPoint m_pos;//记录label和鼠标相对位置

};

#endif // MOUSEDIALOG_H
