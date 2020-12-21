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

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include "keypresseshandler.h"


//////////////////*Game sequence*////////////////////
//1-create a block
//2-push it in a container
//3-paint

class game : public QWidget
{
     Q_OBJECT
public:
    game();

    void InitGame();
    void StartGame();
    void StopGame();

    void SetGameSpeed(int speed);

protected:
    void keyPressEvent(QKeyEvent* event) override;
    bool event(QEvent* event) override;

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
    QVector<TetrisShape*>    _BlocksContainer;
    QVector<TetrisShape*>   _NewBlocksContainer;


    CollisionDetector       _collisionDetector;

    KeyPressesHandler KeyPressesHandler;


};

#endif // GAME_H
