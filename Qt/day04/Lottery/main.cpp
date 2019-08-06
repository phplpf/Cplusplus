#include "lotterydialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LotteryDialog w;
    w.show();

    return a.exec();
}
