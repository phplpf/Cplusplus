#include <QApplication>
#include <QLabel>
int main(int argc,char** argv){
    //创建Qt应用程序对象
    QApplication app(argc,argv);

    //创建标签控件(组件\部件\构件)
    QLabel label("Hello Qt!");
    //显示标签
    label.show();
    
    //让应用程序进入事件循环
    return app.exec();
}



