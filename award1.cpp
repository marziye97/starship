#include "award1.h"
#include <QTimer>
#include <QGraphicsRectItem>

Award1::Award1(QGraphicsItem *parent):Award(parent)
{
    award1=10;
    //QPixmap watermark(":/icoMenu/pic/award1.png");
    //watermark.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    //QPixmap watermark(QSize(10,10));
    //watermark.load(":/pic/award1.png");

    setPixmap(QPixmap(":/pic/award1.png"));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer -> start(50);
}

int Award1::getaward1()
{
    return award1;
}
