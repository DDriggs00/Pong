#ifndef SCORING_H
#define SCORING_H

#include <QGraphicsTextItem>

class scoring: public QGraphicsTextItem
{
public:
    scoring();
    void refresh();
    void pointcpu();
    int getcpuscore();
    void pointplayer();
    int getplayerscore();
    void reset();
private:
    int playerpoints = 0;
    int cpupoints = 0;
};

#endif // SCORING_H
