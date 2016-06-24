#include "spaceship.h"
#include <QGraphicsScene>
#include "game.h"
#include <QList>
#include <typeinfo>
#include <stdlib.h> // rand() -> really large int

extern Game * game;

Spaceship::Spaceship(QGraphicsItem *parent):Enemy(parent)
{
    power=20;
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the rect
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/pic/ship.gif"));
}

int Spaceship::getpower()
{
    return power;
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
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 900){
        scene()->removeItem(this);
        delete this;
    }
}
