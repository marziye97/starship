#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Spaceship:public QObject,public QGraphicsPixmapItem{
      Q_OBJECT
public:
    Spaceship(QGraphicsItem * parent=0);
    int getpower();
    void setpower(int);
private slots:
    void move();
private:
    int power;
};

#endif // SPACESHIP_H
