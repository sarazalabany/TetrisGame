#ifndef GAME_H
#define GAME_H


#include "shapeDim.h"
#include <QObject>
#include <QDebug>
#include "globals.h"
#include "tetrisshape.h"
#include "glwindow.h"

//this shoudl contain a container of shapes  that keeps track of the shapes which I currently have
//int the game


//////////////////*Game sequence*////////////////////
//1-create a block
//2-push it in a container
//3-clear the screen
//4-create a new block
//5-push
//push block in a container


class game : public QObject
{
     Q_OBJECT
public:
    game();

    void InitGame();
    void StartGame();
    void StopGame();

    void SetGameSpeed(int speed);

public slots:
    void OnTimerTimeOut();

private:
    void AddBlockToContainer();
    void MoveBlockWithTime();

    GlWindow    *GlWindow_obj;
    TetrisShape *blockObj;
    QTimer      *MoveBlockstimer;
    int         GameSpeed;
};

#endif // GAME_H
