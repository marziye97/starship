#include "game.h"
#include <QBrush>
#include <QImage>

//it's the main class of this project ;)

Game::Game(QWidget *parent)
{

    scene = new QGraphicsScene();
    scene ->setSceneRect(0,0,800,600);
    setBackgroundBrush(QImage(":/pic/bg.jpg"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player = new Player();
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    show();
}


