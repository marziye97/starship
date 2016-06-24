#ifndef AWARD2_H
#define AWARD2_H
#include "award.h"

class Award2:public Award{
public:
    Award2(QGraphicsItem * parent=0);
    int getaward2();
private:
    int award2;
public slots:
    void move();
};

#endif // AWARD2_H
