#ifndef GAME_H
#define GAME_H

#include "playerpaddle.h"
#include "cpupaddle.h"
#include "ball.h"
#include "scoring.h"
#include "intro.h"
#include "end.h"

#include <QGraphicsScene>
#include <QGraphicsView>

class game: public QGraphicsView
{
public:
    game();

    end* e;
    QGraphicsScene* scene;
    intro* i;
    playerpaddle* pp;
    cpupaddle* cp;
    ball* b;
    scoring* score;
private:
    int height = 480;
    int width = 640;
    int difficulty = 15;

};

#endif // GAME_H
