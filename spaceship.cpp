#include "spaceship.h"
#include <QGraphicsScene>
#include "game.h"
#include <QList>
#include <typeinfo>
#include <stdlib.h>
#include <QDebug>
#include <QTimer>

extern Game * game;

Spaceship::Spaceship(QGraphicsItem *parent): QObject() , QGraphicsPixmapItem(parent)
{
    power=20;
    int random_number = rand() % 700;
    setPos(random_number,0);
    setPixmap(QPixmap(":/pic/ship.gif"));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

int Spaceship::getpower()
{
    return power;
}

void Spaceship::setpower(int npower)
{
    power =power - npower;
   qDebug()<<power;
//   return power;
}
void Spaceship::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()+5);

    if (pos().y() > 900){
        scene()->removeItem(this);
        delete this;
    }
}
