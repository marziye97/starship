#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"

class Game:public QGraphicsView
{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene *scene;
    Score *score;
    Player *player;
    Health *health;

};

#endif // GAME_H
