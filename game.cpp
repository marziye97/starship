#include "game.h"
#include <QBrush>
#include <QImage>
#include <QTimer>

//it's the main class of this project ;)

Game::Game(QWidget *parent)
{

    scene = new QGraphicsScene();
    scene ->setSceneRect(0,0,1000,900);
    setBackgroundBrush(QImage(":/pic/bg.jpg"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,900);

    player = new Player();
    player->setPos(450,600);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}


