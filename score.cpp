#include "score.h"
#include <QFont>
#include "award1.h"
#include <QFont>
#include <QFile>
#include <QString>
#include <QTextStream>
#include<sstream>
#include<string>
#include <QDebug>
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
    qDebug() << score;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score +=100;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increase(int val)
{
    score +=val;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getscore()
{
    return score;
}
