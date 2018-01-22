#include "game.h"

game::game()
{
    //Scene setup
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);

    e = new end();
    i = new intro(width);
    pp = new playerpaddle(height);                  //Create Player Paddle
    b = new ball(height, width, difficulty);        //Create Ball
    cp = new cpupaddle(height, width, difficulty);  //Create Computer Paddle
    score = new scoring();                          //Create score

    scene->addItem(e);  //render Game Over message
    scene->addItem(i);  //render Intro Message
    scene->addItem(cp); //render Player Paddle
    scene->addItem(pp); //render Computer Paddle
    scene->addItem(b);  //render Ball
    scene->addItem(score);//render score

    //Setup View
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width,height);
    show(); //Display gui
}
