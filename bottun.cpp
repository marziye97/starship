#include "button.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "game.h"

extern Game *game;
Button::Button(/*QGraphicsItem *parent,*/QString pic)

{
    setPixmap(QPixmap(pic));
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
