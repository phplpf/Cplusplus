#include <QApplication>
#include "TimeDialog.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    TimeDialog time;
    time.show();

    return app.exec();
}
