#include "intro.h"

#include <QFont>
#include <QGraphicsScene>

intro::intro(int w)
{
    setPlainText(QString("Controls:\nMove Paddle Up: W or Up arrow\nMove Paddle Down: S or Down Arrow\nLaunch ball: Spacebar\nExit: Escape"));
    setFont(QFont("times",16));
    int length = toPlainText().size();
    setPos(w/2-length,50);
}

void intro::hide()
{
    scene()->removeItem(this);
}

intro::~intro()
{
    scene()->removeItem(this);
    delete this;
}
