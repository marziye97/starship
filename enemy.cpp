#include "enemy.h"
#include <QTimer>
#include "game.h"

extern Game * game;
enemy::enemy(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}
