#include "wallview.h"
#include "maincontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    MainModel model;
    MainController controller(&model, argc, argv);
    WallView w(&model);
    w.show();
    return controller.run();
}
