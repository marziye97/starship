#ifndef BUBBLE1_H
#define BUBBLE1_H
#include "bubble.h"

class Bubble1:public Bubble{
public:
    Bubble1(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BUBBLE1_H
