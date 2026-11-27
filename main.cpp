#include "wallview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainModel model;
    WallView w(&model);
    w.show();
    return a.exec();
}
