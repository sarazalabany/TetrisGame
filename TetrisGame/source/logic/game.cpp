#include "game.h"
#include <QTimer>


Game_C::Game_C()
{
    _glWindow = new GlWindow_C();
    _gameUi  	=  new GameUi_C;
//    GlWindow_obj->installEventFilter(this);
//    GameUi_obj->installEventFilter(this);
    _keyPressesHandler = new KeyPressesHandler_C;

}

void Game_C::InitGame()
{
    _gameUi->show();
    _gameUi->InitGameWindow(_glWindow);
    _gameUi->DisplayGame();

    //init timer/create Timer
    _moveBlocksTimer = new QTimer();
    connect(_moveBlocksTimer, &QTimer::timeout, this, &Game_C::OnTimerTimeOut);
    connect(this, &Game_C::blockStopped, this, &Game_C::OnblockStopped);

    SetGameSpeed(GAME_SPEED_1_HZ);

}


void Game_C::AddBlockToContainer()
{

}

void Game_C::StartGame()
{
    _moveBlocksTimer->start(_gameSpeed);

    CreateBlock();
}


void Game_C::StopGame()
{

}

void Game_C::SetGameSpeed(int speed)
{
    _gameSpeed = speed;
}


bool Game_C::eventFilter(QObject *obj, QEvent *event)
{

    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        qDebug("key press is %d", keyEvent->key());
        _keyPressesHandler->HandleKeyPress( &_blockObj->corners,  keyEvent->key(), _FinishedBlocksContainer);

        return true;
    }

   else
   {
        // standard event processing
        return QObject::eventFilter(obj, event);
   }
}

void Game_C::OnTimerTimeOut()
{
    qDebug()<<"Timeout";
    qDebug()<<" Corner 1 Now is: "<<_blockObj->corners.corner1.x << ", " << _blockObj->corners.corner1.y;
    MoveBlockWithTime();



}

void Game_C::OnblockStopped()
{
    _FinishedBlocksContainer.push_back(&_blockObj->corners);
    CreateBlock();
    qDebug()<<"Pushed a block in container";


}


void Game_C::_UpdateWindow()
{
    //paint tetris blocks
    _glWindow->SetOpenGlBuffer(_NewBlocksContainer);
    _glWindow->PaintTetrisScreen();

}

void Game_C::MoveBlockWithTime()
{

    if(_collisionDetector.CheckGameBottomBorder(_FinishedBlocksContainer, &_blockObj->corners))
    {

        emit blockStopped();
        return;
    }
    _blockObj->corners.corner1.y -= static_cast<float>(2.0f * windowGridUnitY);
    _blockObj->corners.corner2.y -= static_cast<float>(2.0f * windowGridUnitY);

    _blockObj->corners.corner3.y -= static_cast<float>(2.0f * windowGridUnitY);
    _blockObj->corners.corner4.y -= static_cast<float>(2.0f * windowGridUnitY);

}

void Game_C::CreateBlock()
{
     qDebug()<<"Created a new shape";
    _blockObj= new TetrisShape_C;

   //create a tetris block
   Square_C block(2.0f * windowGridUnitY, 2.0f *  windowGridUnitX);

   Point_C start_position;
   start_position.x = -1.0f * windowGridUnitX;
   start_position.y = 1.0f;

   Randomize_C randomObject;
   RGBColor_C color = randomObject.GetRandomColor();

   //create shape
   _blockObj->CreateShape(block, start_position, color);

   //insert shape in container
   _NewBlocksContainer.push_back(_blockObj);

   _UpdateWindow();


}


