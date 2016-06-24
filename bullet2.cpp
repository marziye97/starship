#include "bullet2.h"
#include <QTimer>
#include <QList>
#include "game.h"
#include "spaceship.h"
#include "award1.h"
#include "award2.h"
#include <stdlib.h>
#include <typeinfo>

extern Spaceship * ship;
extern Game * game;

Bullet2::Bullet2(QGraphicsItem *parent):Bullet(parent)
{
    power2=10;
    setPixmap(QPixmap(":/pic/bullet2.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet2::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Spaceship)){
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
            /*if(power2 == ship->getpower()){
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }
            else{
                power2 -= ship->getpower();
                continue;
            }*/
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
