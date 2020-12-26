#ifndef GAME_H
#define GAME_H


#include "shapeDim.h"
#include <QObject>
#include <QDebug>
#include "globals.h"
#include "tetrisshape.h"
#include "glwindow.h"
#include "collisiondetector.h"
#include <QVector>

#include "randomize.h"

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include "keypresseshandler.h"


//////////////////*Game sequence*////////////////////
//1-create a block
//2-push it in a container
//3-paint

class game : public QObject
{
     Q_OBJECT
public:
    game();

    void InitGame();
    void StartGame();
    void StopGame();
    void SetGameSpeed(int speed);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void blockStopped();

public slots:
    void OnTimerTimeOut();
    void OnblockStopped();

private:
    void AddBlockToContainer();
    void MoveBlockWithTime();
    void CreateBlock();

    GlWindow                *GlWindow_obj;
    TetrisShape             *blockObj;
    QTimer                  *MoveBlockstimer;
    int                      GameSpeed;
    QVector<squareCorners*> _FinishedBlocksContainer;
    QVector<TetrisShape*>   _NewBlocksContainer;


    CollisionDetector       _collisionDetector;
    KeyPressesHandler       *KeyPressesHandler_obj;



    void _UpdateWindow();
};

#endif // GAME_H
