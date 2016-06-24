#ifndef AWARD1_H
#define AWARD1_H
#include "award.h"

class Award1:public Award{
public:
    Award1(QGraphicsItem * parent=0);
    int getaward1();
private:
    int award1;
public slots:
    void move();
};

#endif // AWARD1_H
