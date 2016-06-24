#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "player.h"
#include "game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}
