#include "bubble2.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "player.h"
#include "game.h"

extern Game *game;

Bubble2::Bubble2(QGraphicsItem *parent)
{
    int random_y = rand() % 900;
    setPos(1000,random_y);
    setPixmap(QPixmap(":/pic/bubble.png"));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bubble2::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x()-5,y()+5);
    if(pos().y() > 900){
        scene()->removeItem(this);
        delete this;
    }

}
