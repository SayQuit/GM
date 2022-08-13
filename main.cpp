#include "widget.h"
#include <QApplication>
#include <QDebug>
#define MAINWINDOWMOVE 240,60
#define Mainwindow 1440,900
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget GMwindows1;
    GMwindows1.show();
    GMwindows1.setWindowTitle("诡秘世界");
    GMwindows1.setFixedSize(Mainwindow);
    GMwindows1.move(MAINWINDOWMOVE);





    return a.exec();
}
