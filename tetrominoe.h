#ifndef TETROMINOE_H
#define TETROMINOE_H

#include <QObject>
#include <QDebug>
#include <QPoint>

#include "block.h"


class Tetrominoe : public QObject
{
    Q_OBJECT

    TetrominoeType type;
    QPoint position;

public:
    explicit Tetrominoe(TetrominoeType type, QObject *parent = nullptr);

    QPoint getPosition() const;
    bool setPosition(QPoint newPosition);

    Block relativeMatrix[4][4];

    TetrominoeType getType() const;
    void setType(TetrominoeType newType);

    void rotate(bool clockWise);

};

#endif // TETROMINOE_H
