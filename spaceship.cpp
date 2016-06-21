#include "spaceship.h"
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include <stdlib.h> // rand() -> really large int

extern Game * game;

spaceship::spaceship(QGraphicsItem *parent):Enemy(parent)
{
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the rect
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/pic/ship.gif"));
}
void spaceship::move(){
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health
        //game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
