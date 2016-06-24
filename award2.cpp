#include "award2.h"
#include "game.h"
#include <QTimer>
#include <QList>
#include <typeinfo>

extern Game *game;

Award2::Award2(QGraphicsItem *parent):Award(parent)
{
    award2=40;
    setPixmap(QPixmap(":/pic/award2.png"));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer -> start(50);
}

int Award2::getaward2()
{
    return award2;
}

void Award2::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->score->increase(award2);

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

