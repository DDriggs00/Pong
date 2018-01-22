#include "scoring.h"

#include <QFont>

scoring::scoring() {
    cpupoints = 0;
    playerpoints = 0;

    setPlainText(QString("Player1: ") + QString::number(playerpoints) + QString("\nComputer: ") + QString::number(cpupoints));
    setFont(QFont("times",16));
}

void scoring::refresh() {
    setPlainText(QString("Player1: ") + QString::number(playerpoints) + QString("\nComputer: ") + QString::number(cpupoints));
}

void scoring::pointcpu() {
    cpupoints++;
    refresh();
}
void scoring::pointplayer() {
    playerpoints++;
    refresh();
}
int scoring::getcpuscore() {
    return cpupoints;
}
int scoring::getplayerscore() {
    return playerpoints;
}

void scoring::reset()
{
    playerpoints = 0;
    cpupoints = 0;
    refresh();
}
