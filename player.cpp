#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "spaceship.h"
#include<QGraphicsItem>
#include "bullet1.h"
#include "bullet2.h"
#include "game.h"

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
        if(game->score->getscore()<500){
            Bullet1 * bullet1 = new Bullet1();
            bullet1->setPos(x()+40,y());
            scene()->addItem(bullet1);
        }
        else if(game->score->getscore()>500){
            Bullet2 * bullet2 = new Bullet2();
            bullet2->setPos(x()+40,y());
            scene()->addItem(bullet2);
        }
    }

}

void Player::spawn(){
    // create an spaceship
    Spaceship * ship = new Spaceship();
    scene()->addItem(ship);
}
