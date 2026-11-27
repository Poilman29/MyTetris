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
    tetrominoe = new Tetrominoe(TetrominoeType::T);
    // tetrominoe->setRotationState(0);

    mainModel->setTetrominoe(tetrominoe);
    mainModel->updateModel();

    return mainThread->exec();
}
