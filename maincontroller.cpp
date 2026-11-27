#include "maincontroller.h"

MainController::MainController(MainModel* mainModel, int argc, char *argv[])
    : mainModel(mainModel)
{
    mainThread = new QApplication(argc, argv);
}

 MainController::~MainController()
{
     delete mainThread;
}

int MainController::run()
{
    return mainThread->exec();
}
