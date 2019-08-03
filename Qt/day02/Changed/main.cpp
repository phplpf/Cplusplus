#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QDialog>
int main(int argc,char** argv){
    QApplication app(argc,argv);
    
    QDialog parent;//父窗口
    parent.resize(320,240);
    //创建水平滑块
    QSlider slider(Qt::Horizontal,&parent);
    slider.move(50,100);
    slider.setRange(0,100);
    //创建选值框
    QSpinBox spin(&parent);
    spin.move(150,100);
    spin.setRange(0,100);
    spin.setSuffix(" 岁");
    //显示父窗口
    parent.show();
    //滑块滑动,选值框数值随之改变
    QObject::connect(
        &slider,SIGNAL(valueChanged(int)),
        &spin,SLOT(setValue(int)));
    //选值框数值改变,让滑块也随之滑动
    QObject::connect(
        &spin,SIGNAL(valueChanged(int)),
        &slider,SLOT(setValue(int)));

    return app.exec();
}



