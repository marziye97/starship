#ifndef AWARD_H
#define AWARD_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Award:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Award(QGraphicsItem * parent=0);
public slots:
    virtual void move()=0;
};


#endif // AWARD_H
