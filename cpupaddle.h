#ifndef CPUPADDLE_H
#define CPUPADDLE_H

#include <QObject>
#include <QGraphicsRectItem>


class cpupaddle: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    cpupaddle(int, int, int);
    ~cpupaddle(){}
public slots:
    void follow();
private:
    int screenh;
    int screenw;
    int paddlelength;
    int difficulty;
};

#endif // CPUPADDLE_H
