#include <QFont>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <sstream>
#include <string>
#include <QDebug>
#include "level.h"
#include "game.h"

extern Game *game;
Level::Level(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    QFile levelFile("C:/Users/Marzi/Documents/starship/level.txt");
    if(!levelFile.exists())
        qDebug()<<"doesn't exist";
    if(!levelFile.open(QFile::ReadOnly|QFile::Text)){
        return;
    }
    QTextStream in(&levelFile);
    QString s = in.readAll();
    level = s.split(" ")[0].toInt();
    qDebug() << level;
    levelFile.close();
    setPlainText(QString("Level: ") + QString::number(level));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Level::increase()
{
    game->score->setscore(0);
    game->health->sethealth(7);
    level ++;
    QFile levelFile("C:/Users/Marzi/Documents/starship/level.txt");
    if(!levelFile.exists())
        qDebug()<<"doesn't exist";
    if(!levelFile.open(QFile::WriteOnly|QFile::Text)){
        return;
    }
    QTextStream out(&levelFile);
    out << QString::number(level);
    qDebug() << level;
    levelFile.close();
    setPlainText(QString("level: ") + QString::number(level));
}

int Level::getlevel()
{
    return level;
}
