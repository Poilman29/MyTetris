#include "tetrominoe.h"


Tetrominoe::Tetrominoe(TetrominoeType type, QObject *parent)
    : QObject{parent}
{
    position = QPoint(5,7);
    setType(type);
}


TetrominoeType Tetrominoe::getType() const
{
    return type;
}

void Tetrominoe::setType(TetrominoeType newType)
{
    type = newType;

    for (int i=0 ; i<4 ; i++){
        for (int j=0 ; j<4 ; j++){
            relativeMatrix[j][i].setBlock(false,false,type);
        }
    }

    switch(this->type){
    case TetrominoeType::I :
        relativeMatrix[1][0].setBlock(true,true,type);
        relativeMatrix[1][1].setBlock(true,true,type);
        relativeMatrix[1][2].setBlock(true,true,type);
        relativeMatrix[1][3].setBlock(true,true,type);
        break;
    case TetrominoeType::O :
        relativeMatrix[0][0].setBlock(true,true,type);
        relativeMatrix[1][0].setBlock(true,true,type);
        relativeMatrix[0][1].setBlock(true,true,type);
        relativeMatrix[1][1].setBlock(true,true,type);
        break;
    case TetrominoeType::T :
        relativeMatrix[0][0].setBlock(true,true,type);
        relativeMatrix[0][1].setBlock(true,true,type);
        relativeMatrix[0][2].setBlock(true,true,type);
        relativeMatrix[1][1].setBlock(true,true,type);
        break;
    case TetrominoeType::L :
        relativeMatrix[0][1].setBlock(true,true,type);
        relativeMatrix[0][2].setBlock(true,true,type);
        relativeMatrix[0][3].setBlock(true,true,type);
        relativeMatrix[1][1].setBlock(true,true,type);
    case TetrominoeType::J :

        break;

    case TetrominoeType::Z :

        break;
    case TetrominoeType::S :

        break;
    default:
        qInfo() << "Unknown Tetrominoe Type";
    }
}

void Tetrominoe::rotate(bool clockWise)
{
    Block newRelativeMatrix[4][4];
    if(clockWise){
        for (int i = 0 ; i < 4 ; i++) {
            for(int j=0 ; j < 4 ; j++){
                newRelativeMatrix[i][j].setIsVisible(relativeMatrix[4-j-1][i].getIsVisible());
            }
        }
    }
    else {
        for (int i = 0 ; i < 4 ; i++) {
            for(int j=0 ; j < 4 ; j++){
                newRelativeMatrix[i][j].setIsVisible(relativeMatrix[j][4-i-1].getIsVisible());
            }
        }
    }
    for (int i = 0 ; i < 4 ; i++) {
        for(int j=0 ; j < 4 ; j++){
            relativeMatrix[i][j].setIsVisible(newRelativeMatrix[i][j].getIsVisible());
        }
    }
}


QPoint Tetrominoe::getPosition() const
{
    return position;
}

bool Tetrominoe::setPosition(QPoint newPosition)
{
    if( (newPosition.x() > 20) && (newPosition.x() <0) ){
        //qInfo()  << " new Tetrominoe in x = " <<  newPosition.x() << " is not allowed" ;
        return false;
    }else if(newPosition.y() < 0){
        //qInfo()  << " new Tetrominoe in y = " <<  newPosition.y() << " is not allowed" ;
        return false;
    }
    position = newPosition;
    return true;
}
