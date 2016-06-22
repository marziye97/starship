#include "award1.h"
#include <QTimer>
#include <QGraphicsRectItem>

Award1::Award1(QGraphicsItem *parent):Award(parent)
{
    award1=10;
    setPixmap(QPixmap(":/pic/bullet2.png"));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer -> start(50);
}

int Award1::getaward1()
{
    return award1;
}
