#include "ball.h"
#include "scoring.h"
#include "game.h"

#include <QList>
#include <QTimer>
#include <cstdlib> //for rand
#include <ctime>   //for rand seed

extern game* g;

ball::ball(int h, int w, int d) {
    setRect(0,0,20,20);
    setPos((w/2-10),(h/2-10));
    difficulty = d;
    speed = 2;
    screenh = h;
    screenw = w;
}

void ball::launch(){
    srand(time(NULL));  //randomize random numbers
    if(rand() % 2 == 0)
        hmove = -1;
    else
        hmove = 1;
    if(rand() % 2 == 0)
        vmove = -1;
    else
        vmove = 1;
    launchable = false;

    QTimer *timer = new QTimer();
    timer->start(12.5);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    QTimer *timer2 = new QTimer();
    timer2->start(10000);
    connect(timer2, SIGNAL(timeout()), this, SLOT(speedup()));
}

void ball::relaunch()
{
    //Display prompt

    speed = 2;
    srand(time(NULL));  //randomize random numbers
    if(rand() % 2 == 0)
        hmove = -1;
    else
        hmove = 1;
    if(rand() % 2 == 0)
        vmove = -1;
    else
        vmove = 1;

    launchable = false;
}

bool ball::canLaunch()
{
    return launchable;
}

void ball::speedup() {
    speed += 0.5;
}

void ball::move() {

    setPos(x() + hmove * speed, y() + vmove * speed);

    //Collision management
    QList<QGraphicsItem *> Collisions = collidingItems();
    if(Collisions.size() == 1) {
        if(typeid(*(Collisions[0])) != typeid(scoring))
            hmove = -hmove;
    }
    else if(Collisions.size() != 0) {
        hmove = -hmove;
    }

    //Top of screen and Bottom of screen
    if(pos().y() <= 0 || pos().y() + 20 >= screenh){
        vmove = -vmove;
    }

    //scoring

    if(pos().x() <= 0){ //PlayerMisses
        g->score->pointcpu();
        vmove = hmove = 0;
        setPos((screenw/2-10),(screenh/2-10));
                if(g->score->getcpuscore() >= winPts) {
                    g->e->cwin(screenw);
                }
        launchable = true;
    }

    if(pos().x() >= screenw-20){//cpu misses
        g->score->pointplayer();
        vmove = hmove = 0;
        setPos((screenw/2-10),(screenh/2-10));
        if(g->score->getplayerscore() >=winPts) {
            g->e->pwin(screenw);
        }
        launchable = true;
    }
}
