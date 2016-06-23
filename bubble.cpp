#include "bubble.h"
#include <stdlib.h>
#include "spaceship.h"
#include <QLineF>
#include <QTimer>

Bubble::Bubble(QGraphicsItem *parent):Enemy(parent)
{
    int random_number = rand() % 900;
    setPos(random_number,0);
    setPixmap(QPixmap(":/pic/bullet1.png"));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bubble::move()
{
    int random_x1=rand() % 900;
    int random_y1=rand() % 800;
    int random_x2=rand() % 900;
    int random_y2=rand() % 800;
    QLineF ln(random_x1,random_y1,random_x2,random_y2);

}
