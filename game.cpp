#include "game.h"
#include <QBrush>
#include <QImage>
#include <QTimer>
#include "button.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <sstream>
#include <string>
#include <QDebug>
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
    //show();

    //menu();
}
void Game::menu(){
    play = new Button(QString(":/pic/play-icon.png"));
    play->setPos(300,300);
    scene->addItem(play);
    connect(play,SIGNAL(clicked()),this,SLOT(start()));

}
void Game::start(){
    qDebug() << "start";
    scene->removeItem(play);
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
    level = new Level();
    level->setPos(level->x(),level->y()+50);
    scene->addItem(level);

    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

}
void Game::gameOver(){
    scene->removeItem(player);
    scene->removeItem(score);
    scene->removeItem(health);
    play = new Button(QString(":/pic/gameOver.gif"));
    play->setPos(350,300);
    scene->addItem(play);
    //connect(play,SIGNAL(clicked()),this,SLOT(start()));
}

