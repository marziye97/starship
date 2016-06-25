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


Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene ->setSceneRect(0,0,1000,900);
    setBackgroundBrush(QImage(":/pic/bg.jpg"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,900);
}
void Game::menu(){
    play = new Button(QString(":/pic/play-icon.png"));
    play->setPos(300,400);
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
    score->setscore(0);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    health->sethealth(7);
    level = new Level();
    level->setPos(level->x(),level->y()+50);
    scene->addItem(level);
    level->setlevel(1);


    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

}

void Game::Restart()
{
    qDebug() << "Restart";
    //scene->clear();
    scene->removeItem(level);
    delete level;
    scene->removeItem(score);
    delete score;
    scene->removeItem(health);
    delete health;
    scene->removeItem(player);
    delete player;
    scene->removeItem(restart);
    scene->removeItem(exit);
    player = new Player();
    player->setPos(450,600);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    score->setscore(0);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    health->sethealth(7);
    level = new Level();
    level->setPos(level->x(),level->y()+50);
    scene->addItem(level);
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

}
void Game::gameOver(){
    restart = new Button(QString(":/pic/restart.png"));
    restart->setPos(300,300);
    scene->addItem(restart);
    exit = new Button(QString(":/pic/exit.png"));
    exit->setPos(300,400);
    scene->addItem(exit);
    qDebug() << "restart";
    connect(restart,SIGNAL(clicked()),this,SLOT(Restart()));
    qDebug() << "restart";
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
}

