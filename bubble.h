#ifndef BUBBLE_H
#define BUBBLE_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Bubble:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bubble(QGraphicsItem * parent=0);
private slots:
    virtual void move()=0;
};

#endif // BUBBLE_H
