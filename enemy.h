#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QGraphicsPixmapItem>

class enemy:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    enemy(QGraphicsItem * parent=0);
public slots:
    virtual void move() = 0;
};


#endif // ENEMY_H
