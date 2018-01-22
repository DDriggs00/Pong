#ifndef INTRO_H
#define INTRO_H

#include <QGraphicsTextItem>

class intro: public QGraphicsTextItem
{
public:
    intro(int);
    void hide();
    ~intro();
};

#endif // INTRO_H
