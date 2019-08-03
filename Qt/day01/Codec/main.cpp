#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextCodec>
int main(int argc,char** argv){
    QApplication app(argc,argv);
    QTextCodec* codec = 
        QTextCodec::codecForName("GBK");
    /*QString str1 = 
        codec->toUnicode("我是标签");
    QString str2 =
        codec->toUnicode("我是按钮");*/
    QLabel label(
        codec->toUnicode("我是标签"));
    label.show();
    QPushButton button(
        codec->toUnicode("我是按钮"));
    button.show();
    return app.exec();
}


