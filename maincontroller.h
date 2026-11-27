#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QApplication>

#include "mainmodel.h"

class MainController
{    
    QApplication* mainThread;
    MainModel* mainModel;

public:
    MainController(MainModel *mainModel, int argc, char *argv[]);
    ~MainController();
    int run();
};

#endif // MAINCONTROLLER_H
