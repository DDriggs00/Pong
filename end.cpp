#include "end.h"

#include <QFont>
#include <QGraphicsScene>

end::end()
{
    setPlainText(QString(""));
    setFont(QFont("times",16));
    setPos(-100, -100);

}

void end::cwin(int w)
{
    setPlainText(QString("Game Over! Computer Wins.\nPress Space to Play Again\nor Escape to Quit"));
    setPos(w/2-100,50);
    NewGame = true;
}

void end::pwin(int w)
{
    setPlainText(QString("Game Over! Player Wins.\nPress Space to Play Again\nor Escape to Quit"));
    setPos(w/2-100,50);
    NewGame = true;
}

void end::Hide()
{
    setPlainText(QString(""));
    setPos(-100, -100);
}

bool end::isNewGame()
{
    return NewGame;
}

void end::setNewGame(bool ng)
{
    NewGame = ng;
}
