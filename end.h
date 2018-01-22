#ifndef END_H
#define END_H

#include <QGraphicsTextItem>

class end: public QGraphicsTextItem
{
public:
    end();
    void cwin(int w);
    void pwin(int w);
    void Hide();
    bool isNewGame();
    void setNewGame(bool);
private:
    bool NewGame = false;
};

#endif // END_H
