#include "score.h"
#include "award1.h"
#include <QFont>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <sstream>
#include <string>
#include <QDebug>
#include "game.h"
#include <Windows.h>

extern Game *game;
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    QFile scoreFile("C:/Users/Marzi/Documents/starship/score.txt");
    if(!scoreFile.exists())
        qDebug()<<"doesn't exist";
    if(!scoreFile.open(QFile::ReadOnly|QFile::Text)){
        return;
    }
    QTextStream in(&scoreFile);
    QString s = in.readAll();
    score = s.split(" ")[0].toInt();
    scoreFile.close();
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score +=100;
    QFile scoreFile("C:/Users/Marzi/Documents/starship/score.txt");
    if(!scoreFile.exists())
        qDebug()<<"doesn't exist";
    if(!scoreFile.open(QFile::WriteOnly|QFile::Text)){
        return;
    }
    QTextStream out(&scoreFile);
    out << QString::number(score);
    scoreFile.close();
    setPlainText(QString("Score: ") + QString::number(score));
    if(score >= (game->level->getlevel()*1000)){
        game->level->increase();
    }
}

void Score::increase(int val)
{
    score +=val;
    QFile scoreFile("C:/Users/Marzi/Documents/starship/score.txt");
    if(!scoreFile.exists())
        qDebug()<<"doesn't exist";
    if(!scoreFile.open(QFile::WriteOnly|QFile::Text)){
        return;
    }
    QTextStream out(&scoreFile);
    out << QString::number(score);
    scoreFile.close();
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getscore()
{
    return score;
}

void Score::setscore(int nscore)
{
    score = nscore;
    QFile scoreFile("C:/Users/Marzi/Documents/starship/score.txt");
    if(!scoreFile.exists())
        qDebug()<<"doesn't exist";
    if(!scoreFile.open(QFile::WriteOnly|QFile::Text)){
        return;
    }
    QTextStream out(&scoreFile);
    out << QString::number(score);
    scoreFile.close();
    setPlainText(QString("Score: ") + QString::number(score));
}
