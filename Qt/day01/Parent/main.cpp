#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
int main(int argc,char** argv){
    QApplication app(argc,argv);
    
    //创建父窗口对象
    //QWidget parent;
    //QMainWindow parent;//主窗口
    QDialog parent;//对话框
    parent.move(100,100);//相对屏幕左上角
    parent.resize(320,240);

    //创建标签控件,并停靠在父窗口上面
    QLabel label("我是标签",&parent);
    label.move(50,50);//相对父窗口左上角
    
    //创建按钮控件,并停靠在父窗口上面
    QPushButton button("我是按钮",&parent);
    button.move(50,150);
    button.resize(80,80);

    //使用new在堆区创建按钮控件
    QPushButton* pbutton = 
        new QPushButton("动态按钮",&parent);
    pbutton->move(200,150);
    pbutton->resize(80,80);

    //显示父窗口,上面停靠的控件也会一起显示
    parent.show();
    
    return app.exec();
}





