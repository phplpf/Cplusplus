#include "receiverdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReceiverDialog w;
    w.show();

    return a.exec();
}
