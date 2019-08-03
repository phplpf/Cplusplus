#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
int main(int argc,char** argv){
    QApplication app(argc,argv);
    
    //1)创建GBK编码对象
    QTextCodec* codec = 
        QTextCodec::codecForName("GBK");
    //2)将显示字符串转换为unicode
    QString str = 
        codec->toUnicode("下午有点困!");

    QPushButton button(str);
    button.show();

    return app.exec();
}

