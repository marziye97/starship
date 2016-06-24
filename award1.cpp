#include "award1.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QList>
#include <typeinfo>

extern Game *game;
Award1::Award1(QGraphicsItem *parent):Award(parent)
{
    award1=20;
    setPixmap(QPixmap(":/pic/award1.png"));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer -> start(50);
}

int Award1::getaward1()
{
    return award1;
}

void Award1::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->score->increase(award1);

            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    setPos(x(),y()+5);
    if(pos().y() > 900){
        scene()->removeItem(this);
        delete this;
    }
}
