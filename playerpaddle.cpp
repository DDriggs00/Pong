#include "playerpaddle.h"
#include "game.h"

#include <QKeyEvent>
#include <QGraphicsItem>

extern game* g;

playerpaddle::playerpaddle(int h) {
    setRect(0,0,20,100);
    setPos(0,(h-100)/2);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    screenh = h;
}

//Up+Down Arrows
void playerpaddle::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_W){
        if(pos().y() >= 0){
            setPos(x(),y()-10);
        }
    }
    if(event->key() == Qt::Key_Down || event->key() == Qt::Key_S){
        if(pos().y() + 100 <= screenh){
            setPos(x(),y()+10);
        }
    }
    //Ball Management
    if(event->key() == Qt::Key_Space){
        if(firstball) {
            g->i->hide();
            g->b->launch();
            firstball = false;
        }
        else if(g->b->canLaunch()) {
            if(g->e->isNewGame()) {
                g->e->hide();
                g->e->setNewGame(false);
                g->score->reset();
            }
            g->b->relaunch();
        }
    }

    if(event->key() == Qt::Key_Escape) {
        exit(0);
    }
}
