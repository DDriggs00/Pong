#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QGraphicsRectItem>


class ball: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ball(int, int, int);
    void launch();
    void relaunch();
    bool canLaunch();
public slots:
    void move();
    void speedup();

private:
    int vmove = 0;
    int hmove = 0;
    int screenh;
    int screenw;
    int difficulty;
    int speed;
    bool launchable = true;
};

#endif // BALL_H
