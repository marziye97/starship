#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "spaceship.h"
#include "award1.h"
#include "award2.h"
#include <stdlib.h>
#include <typeinfo>

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Spaceship)){
            // increase the score
            game->score->increase();
            int random_numbetr= (rand()%2)+1;
            if(random_numbetr == 1){
                Award1 * award1 = new Award1();
                award1->setPos(x(),y());
                scene()->addItem(award1);
            }
            else if(random_numbetr == 2){
                Award2 * award2 = new Award2();
                award2->setPos(x(),y());
                scene()->addItem(award2);
            }
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-10);
//    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
