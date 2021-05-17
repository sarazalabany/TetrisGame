#include "game.h"
#include <QTimer>


Game_C::Game_C()
 :_gameUi(new GameUi_C)
 ,_gameStartWindow(new StartGameWindow_C(_gameUi))
 ,_glWindow(new GlWindow_C)
 ,_keyPressesHandler(new KeyPressesHandler_C)
{

    connect(_gameStartWindow, &StartGameWindow_C::startGameButtonPressed, this, &Game_C::OnStartGame);

    //init timer/create Timer
    _moveBlocksTimer = new QTimer();
    connect(_moveBlocksTimer, &QTimer::timeout, this, &Game_C::OnTimerTimeOut);
    connect(this, &Game_C::blockStopped, this, &Game_C::OnblockStopped);
    //GlWindow_obj->installEventFilter(this);
    //GameUi_obj->installEventFilter(this);

    //set window to the start menu
    _gameUi->SetWindow(_gameStartWindow.data());
    _gameUi->show();

}

void Game_C::OnStartGame()
{
    _gameSpeed = GAME_SPEED_1_HZ;

    //show openGl screen in the mainwindow
    _gameUi->SetWindow(_glWindow);
    _glWindow->show(); //show should be called first because i think thsi is what makes opengl context
    _glWindow->Init();
    _glWindow->PaintTetrisScreen();
    StartGame();

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


