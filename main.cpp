//Devin Driggs
//Pong
//
//v0.1: Player paddle, Ball done.
//v0.2: scoring done
//v0.3: Cpupaddle done
//v0.4: menu done

#include <QApplication>
#include <game.h>

game* g;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    g = new game();
    g->show();

    return a.exec();
}
