#include "bubble.h"
#include <stdlib.h>
#include "spaceship.h"
#include <QLineF>
#include <QTimer>

Bubble::Bubble(QGraphicsItem *parent):Enemy(parent)
{
    int random_x = rand() % 800;
    int random_y = rand() % 900;
    setPos(random_x,random_y);
    setPixmap(QPixmap(":/pic/award1.png"));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bubble::move()
{
    setPos(x()-5,y()-5);
    //remove
}
