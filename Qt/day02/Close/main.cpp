#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QDialog parent;//父窗口
    parent.resize(480,320);
    //标签
    QLabel label("我是标签",&parent);
    label.move(50,50);
    //按钮
    QPushButton button("关闭标签",&parent);
    button.move(50,200);
    button.resize(80,80);

    QPushButton button2("退出",&parent);
    button2.move(200,200);
    button2.resize(80,80);

    parent.show();//显示父窗口和控件
    
    //实现点击按钮关闭标签
    QObject::connect(
        &button,SIGNAL(clicked(void)),
        &label,SLOT(close(void)));
    
    //练习:向父窗口中,添加一个退出按钮,实现
    //点击该按钮退出应用程序.
    QObject::connect(
        &button2,SIGNAL(clicked(void)),
        //&app,SLOT(closeAllWindows(void)));
        //&app,SLOT(quit(void)));
        &parent,SLOT(close(void)));


    return app.exec();
}




