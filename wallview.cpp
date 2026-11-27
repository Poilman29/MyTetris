#include "wallview.h"


WallView::WallView(MainModel *mainModel, QWidget *parent)
    : QWidget(parent), mainModel(mainModel)
{
    this->setupUi();
    connect(mainModel,&MainModel::modelUpdated,this,&WallView::updateView);
}

WallView::~WallView()
{

}


void WallView::setupUi()
{
    if (this->objectName().isEmpty())
        this->setObjectName("WallView");
    this->resize(SCREEN_WIDTH, SCREEN_HEIGHT);

   this->setWindowTitle(QCoreApplication::translate("WallView", "WallView", nullptr));

    QMetaObject::connectSlotsByName(this);
}

void WallView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    //qInfo() << "paintEvent : " << QTime::currentTime().toString();
    int squareSize = 30;

    QPainter painter(this);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);

    painter.setPen(pen);

    QBrush brush(QColor(153,102,51,255));
    painter.setBrush(brush);

    // init

    for(int i=0 ; i<20 ; i++){
        for(int j=0 ; j<10 ; j++){
            if(mainModel->getBlock(j,i).getIsVisible()){
                setBlockColor(painter,mainModel->getBlock(j,i));
                painter.drawRect(QRect(20+(j*squareSize),20+(i*squareSize),squareSize,squareSize));
            }
        }
    }
}




void WallView::updateView()
{
    this->repaint();
}


void WallView::setBlockColor(QPainter &painter, Block &block)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    // qInfo() << "In set Color : tetrominoe type = " << block.tetrominoType();

    switch(block.tetrominoType()){
    case TetrominoeType::I :
        brush.setColor(Qt::cyan);
        painter.setBrush(brush);
        break;
    case TetrominoeType::O :
        brush.setColor(Qt::magenta);
        painter.setBrush(brush);
        break;

    case TetrominoeType::T :
        brush.setColor(Qt::yellow);
        painter.setBrush(brush);
        break;

    case TetrominoeType::L :
        // orange
        brush.setColor(QColor(245,173,66));
        painter.setBrush(brush);
        break;

    case TetrominoeType::J :
        brush.setColor(Qt::blue);
        painter.setBrush(brush);
        break;

    case TetrominoeType::Z :
        brush.setColor(Qt::green);
        painter.setBrush(brush);
        break;
    case TetrominoeType::S :
        brush.setColor(Qt::red);
        painter.setBrush(brush);
        break;
    default:
        brush.setColor(QColor(153,102,51,255));
        painter.setBrush(brush);
        qInfo() << "Unknown Tetrominoe Type";
    }
}

void WallView::keyPressEvent(QKeyEvent *event)
{
    // Tetrominoe* currentTetrominoe = this->mainModel->getTetrominoe();
    // int currentTetrominoeType = static_cast<int>(currentTetrominoe->getType());

    switch(event->key())
    {
    case Qt::Key_Left:
        this->mainModel->rotate(true);
        break;

    case Qt::Key_Right:
        this->mainModel->rotate(false);
        break;

    case Qt::Key_Down:
        this->mainModel->changeTetrominoeType();
        break;
    case Qt::Key_Up:
        this->mainModel->changeTetrominoeType();
        break;
    default :
        qDebug() << "Unknown key pressed" ;
    }
    updateView();
}

