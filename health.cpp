#include "health.h"
#include "game.h"
#include <QFont>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <sstream>
#include <string>
#include <QDebug>

extern Game *game;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    QFile healthFile("C:/Users/Marzi/Documents/starship/health.txt");
    if(!healthFile.exists())
        qDebug()<<"doesn't exist";
    if(!healthFile.open(QFile::ReadOnly|QFile::Text)){
        return;
    }
    QTextStream in(&healthFile);
    QString s = in.readAll();
    health = s.split(" ")[0].toInt();
    healthFile.close();
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    if(health==0){
        game->gameOver();
    }
    QFile healthFile("C:/Users/Marzi/Documents/starship/health.txt");
    if(!healthFile.exists())
        qDebug()<<"doesn't exist";
    if(!healthFile.open(QFile::WriteOnly|QFile::Text)){
        return;
    }
    QTextStream out(&healthFile);
    out << QString::number(health);
    healthFile.close();
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::increase()
{
    health++;
    QFile healthFile("C:/Users/Marzi/Documents/starship/health.txt");
    if(!healthFile.exists())
        qDebug()<<"doesn't exist";
    if(!healthFile.open(QFile::WriteOnly|QFile::Text)){
        return;
    }
    QTextStream out(&healthFile);
    out << QString::number(health);
    healthFile.close();
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::gethealth()
{
    return health;
}

void Health::sethealth(int nhealth)
{
    health = nhealth;
    QFile healthFile("C:/Users/Marzi/Documents/starship/health.txt");
    if(!healthFile.exists())
        qDebug()<<"doesn't exist";
    if(!healthFile.open(QFile::WriteOnly|QFile::Text)){
        return;
    }
    QTextStream out(&healthFile);
    out << QString::number(health);
    healthFile.close();
    setPlainText(QString("Health: ") + QString::number(health));
}
