#include "bullet2.h"
#include <QTimer>

Bullet2::Bullet2(QGraphicsItem *parent):Bullet(parent)
{
    setPixmap(QPixmap(":/pic/bullet2.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}
