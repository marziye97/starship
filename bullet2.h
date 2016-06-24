#ifndef BULLET2_H
#define BULLET2_H
#include "bullet.h"

class Bullet2:public Bullet
{
public:
    Bullet2(QGraphicsItem * parent=0);
private:
    int power2;
public slots:
    void move();
};

#endif // BULLET2_H
