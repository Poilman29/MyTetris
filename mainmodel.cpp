#include "mainmodel.h"

MainModel::MainModel(QObject *parent)
    : QObject{parent}
{

}

Block& MainModel::getBlock(int x, int y)
{
    return matrix[y][x];
}

Tetrominoe *MainModel::getTetrominoe() const
{
    return tetrominoe;
}

void MainModel::setTetrominoe(Tetrominoe *newTetrominoe)
{
    tetrominoe = newTetrominoe;
}


void MainModel::updateModel()
{
    int x= tetrominoe->getPosition().x();
    int y= tetrominoe->getPosition().y();

    //qInfo() << "x = " << x << " y = " << y;

    // Update Area with new Tetrominoe
    for(int i=y ; i<y+4 ; i++){
        for(int j=x ; j<x+4 ; j++){
            if (matrix[i][j].getIsVisible() && !tetrominoe->relativeMatrix[i-y][j-x].getIsVisible()){
                matrix[i][j].setBlock(false,false,tetrominoe->getType());
            }
            if (!matrix[i][j].getIsVisible() && tetrominoe->relativeMatrix[i-y][j-x].getIsVisible()){
                matrix[i][j].setBlock(true,true,tetrominoe->getType());
            }
        }
    }

    emit modelUpdated();
}

void MainModel::changeTetrominoeType()
{
    int tetrominoeType = this->getTetrominoe()->getType();
    tetrominoeType++;
    tetrominoeType = (tetrominoeType % 6) ;
    this->tetrominoe->setType(static_cast<TetrominoeType>(tetrominoeType));

    this->updateModel();
}

