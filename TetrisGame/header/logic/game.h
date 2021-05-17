#ifndef GAME_H
#define GAME_H

/*Library Includes*/
#include <QObject>
#include <QDebug>
#include <QVector>
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>

/*Project Includes */
#include "shapeDim.h"
#include "globals.h"
#include "tetrisshape.h"
#include "glwindow.h"
#include "collisiondetector.h"
#include "randomize.h"
#include "keypresseshandler.h"
#include "gameui.h"
#include "startgamewindow.h"

//////////////////*Game sequence*////////////////////
//1-create a block
//2-push it in a container
//3-paint
namespace UI {
class Game_C;
}

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
    void OnStartGame();

private:
    void AddBlockToContainer();
    void MoveBlockWithTime();
    void CreateBlock();

    int                                 _gameSpeed;
    GameUi_C                            *_gameUi;
    QPointer<StartGameWindow_C>   _gameStartWindow;

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
