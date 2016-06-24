#ifndef BUBBLE2_H
#define BUBBLE2_H
#include "bubble.h"

class Bubble2:public Bubble{
public:
    Bubble2(QGraphicsItem * parent=0);
public slots:
    void move();
};
#endif // BUBBLE2_H
