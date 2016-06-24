#ifndef BULLET1_H
#define BULLET1_H
#include"bullet.h"

class Bullet1:public Bullet
{
public:
    Bullet1(QGraphicsItem * parent=0);
private:
    int power1;
public slots:
    void move();
};

#endif // BULLET1_H
