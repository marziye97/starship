#include "bullet1.h"
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

Bullet1::Bullet1(QGraphicsItem *parent):Bullet(parent)
{
    power1=5;
    setPixmap(QPixmap(":/pic/bullet1.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet1::move()
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
            if(power1 == ship->getpower()){
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }
            else{
                power1 -= ship->getpower();
                break;
            }

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
