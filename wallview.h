#ifndef WALLVIEW_H
#define WALLVIEW_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>

#include "common.h"
#include "mainmodel.h"
#include "tetrominoe.h"

class WallView : public QWidget
{
    Q_OBJECT

    MainModel* mainModel;

public:
    WallView(MainModel* mainModel, QWidget *parent = nullptr);
    ~WallView();

public slots:

    void updateView();

private:

    void setBlockColor(QPainter &painter, Block &block);
    void setupUi();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
};
#endif // WALLVIEW_H
