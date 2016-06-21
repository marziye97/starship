#include "award.h"
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
#include "player.h"

//#include <QDebug>

extern Game *game;

Award::Award(QGraphicsItem *parent) : QObject() , QGraphicsPixmapItem(parent)
{
    //QTimer *timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //timer -> start(50);
}

void Award::move()
{
    setPos(x(),y()+5);
    if(pos().y() > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}




