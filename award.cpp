#include "award.h"
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
#include "player.h"
#include "award1.h"
#include <QList>
#include <typeinfo>

extern Game *game;

Award::Award(QGraphicsItem *parent) : QObject() , QGraphicsPixmapItem(parent)
{
}



