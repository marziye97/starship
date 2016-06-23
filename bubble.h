#ifndef BUBBLE_H
#define BUBBLE_H
#include "enemy.h"

class Bubble:public Enemy{
public:
    Bubble(QGraphicsItem * parent=0);
private slots:
    void move();
};

#endif // BUBBLE_H
