#include "cpupaddle.h"
#include "game.h"

#include <QTimer>
#include <cmath>

extern game* g;

cpupaddle::cpupaddle(int h, int w, int d) {
    screenh = h;
    screenw = w;
    difficulty = d;
    paddlelength = 100;

    setRect(0,0,20,paddlelength);
    setPos(w-20,(h-paddlelength)/2);

    QTimer *timer = new QTimer();
    timer->start(25);
    connect(timer, SIGNAL(timeout()), this, SLOT(follow()));
}

void cpupaddle::follow() {
    int Hdif = (y()+paddlelength/2) - (g->b->y()+10);

    int accel = abs(Hdif/50);

    if(Hdif > 0)
        setPos(x(), y()-(difficulty/2)*accel);
    else if(Hdif < 0)
        setPos(x(), y()+(difficulty/2)*accel);
}
