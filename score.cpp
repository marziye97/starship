#include "score.h"
#include <QFont>
#include "award1.h"

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score = 0;
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
