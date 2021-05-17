#ifndef GAME_H
#define GAME_H


/*Project includes */
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
#include "gameui.h"

//////////////////*Game sequence*////////////////////
//1-create a block
//2-push it in a container
//3-paint

class Game_C : public QObject

{
     Q_OBJECT
public:
    //default constructor
    Game_C();

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

    int                      _gameSpeed;
    GameUi_C                 *_gameUi;
    GlWindow_C                *_glWindow;
    TetrisShape_C             *_blockObj;
    QTimer                  *_moveBlocksTimer;
    QVector<SquareCorners_C*> _FinishedBlocksContainer;
    QVector<TetrisShape_C*>   _NewBlocksContainer;

    CollisionDetector_C       _collisionDetector;
    KeyPressesHandler_C       *_keyPressesHandler;


    void _UpdateWindow();

};

#endif // GAME_H
