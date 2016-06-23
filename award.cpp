#include "award.h"
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
#include "player.h"
#include "award1.h"
#include <QList>

//#include <QDebug>

extern Award1 *award1;
extern Game *game;

Award::Award(QGraphicsItem *parent) : QObject() , QGraphicsPixmapItem(parent)
{
    //QTimer *timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //timer -> start(50);
}

void Award::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->score->increase(award1->getaward1());

            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    setPos(x(),y()+5);
    if(pos().y() > 900){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}




