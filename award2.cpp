#include "award2.h"
#include <QTimer>

Award2::Award2(QGraphicsItem *parent):Award(parent)
{
    award2=40;
    //open image
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer -> start(50);
}

int Award2::getaward2()
{
    return award2;
}

