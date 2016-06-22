#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Spaceship:public Enemy
{
public:
    Spaceship(QGraphicsItem * parent=0);
private slots:
    void move();
};

#endif // SPACESHIP_H
