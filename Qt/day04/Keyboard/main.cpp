#include "keyboarddialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyboardDialog w;
    w.show();

    return a.exec();
}
