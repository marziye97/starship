#include "player.h"
#include "bubble1.h"
#include "bubble2.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "spaceship.h"
#include <QGraphicsItem>
#include "bullet1.h"
#include "bullet2.h"
#include "game.h"

Spaceship * ship;
extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //set the picture of player.....

    setPixmap(QPixmap(":/pic/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x()+100 <1000)
        setPos(x()+10 , y());
    }
    else if (event->key() == Qt::Key_Up){
        if(pos().y() >  0)
        setPos(x() , y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        if(pos().y()+100 <900)
        setPos(x() , y()+10);
    }

    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        if(game->level->getlevel() == 1){
            Bullet1 * bullet1 = new Bullet1();
            bullet1->setPos(x()+40,y());
            scene()->addItem(bullet1);
        }
        else if(game->level->getlevel()>= 2){
            if(game->score->getscore() <= 1000){
                Bullet1 * bullet1 = new Bullet1();
                bullet1->setPos(x()+40,y());
                scene()->addItem(bullet1);
            }
            else if(game->score->getscore() >= 1000){
                int angle = -90;
                Bullet2 * bullet2 = new Bullet2();
                bullet2->setPos(x()+40,y());
                Bullet2 * bullet3 = new Bullet2();
                bullet3->setPos(x()+40,y());

                scene()->addItem(bullet2);
                bullet2->setRotation(angle-20);
                game->scene->addItem(bullet2);
                bullet3->setRotation(angle+20);
                game->scene->addItem(bullet3);

            }
        }
    }
}

void Player::spawn(){
    // create an spaceship
    if(game->level->getlevel() >= 3 ){
        Bubble1 *bubble1 = new Bubble1();
        scene()->addItem(bubble1);
        Bubble2 *bubble2 = new Bubble2();
        scene()->addItem(bubble2);
        ship = new Spaceship();
        scene()->addItem(ship);
    }
    else if(game->level->getlevel() <=2){
        ship = new Spaceship();
        scene()->addItem(ship);
    }
}
