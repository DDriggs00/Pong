#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H

#include <QGraphicsRectItem>
#include <QObject>

class playerpaddle: public QObject, public  QGraphicsRectItem
{
    Q_OBJECT
public:
    playerpaddle(int);
    ~playerpaddle(){}
    void keyPressEvent(QKeyEvent* event);
    int getkeypress();
private:
    bool firstball = true;
    int screenh;
};

#endif // PLAYERPADDLE_H
