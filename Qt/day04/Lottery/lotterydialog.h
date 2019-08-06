#ifndef LOTTERYDIALOG_H
#define LOTTERYDIALOG_H

#include <QDialog>
#include <QDir>
#include <QTimer>
#include <QPainter>
#include <QVector>
#include <QDebug>

namespace Ui {
class LotteryDialog;
}

class LotteryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LotteryDialog(QWidget *parent = 0);
    ~LotteryDialog();

private slots:
    //和开始按钮匹配的槽函数
    void on_m_button_clicked();
private:
    //从path路径中加载图片对象到容器
    void loadPhotos(const QString& path);
    //定时器事件处理函数
    void timerEvent(QTimerEvent *);
    //绘图事件处理函数
    void paintEvent(QPaintEvent *);
private:
    Ui::LotteryDialog *ui;
    //容器：用于保存所有的图片对象
    QVector<QImage> m_vecPhotos;
    int m_index;//图片对象在容器中的索引
    int m_timer;//定时器
    bool isStarted;//标记摇奖开始/摇奖停止
};

#endif // LOTTERYDIALOG_H




