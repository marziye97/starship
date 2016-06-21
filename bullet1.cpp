#include "bullet1.h"
#include <QTimer>

Bullet1::Bullet1(QGraphicsItem *parent):Bullet(parent)
{
    setPixmap(QPixmap(":/pic/bullet1.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}
