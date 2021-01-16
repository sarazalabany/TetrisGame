#include "game.h"
#include <QTimer>


game::game(GameUi *gameUi)
    :GameUi_obj(gameUi)
{
    GlWindow_obj = new GlWindow();
    GlWindow_obj->installEventFilter(this);
    KeyPressesHandler_obj = new KeyPressesHandler;

}

void game::InitGame()
{


    //init timer/create Timer
    MoveBlockstimer = new QTimer();
    connect(MoveBlockstimer, &QTimer::timeout, this, &game::OnTimerTimeOut);
    connect(this, &game::blockStopped, this, &game::OnblockStopped);

    SetGameSpeed(GAME_SPEED_1_HZ);


}


void game::AddBlockToContainer()
{

}

void game::StartGame()
{
    MoveBlockstimer->start(GameSpeed);

    CreateBlock();

    //qDebug()<<"Size of _NewBlocksContainer vector is "<<_NewBlocksContainer.size();
}


void game::StopGame()
{

}

void game::SetGameSpeed(int speed)
{
    GameSpeed = speed;
}


bool game::eventFilter(QObject *obj, QEvent *event)
{

    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
//          qDebug("key press is %d", keyEvent->key());
        KeyPressesHandler_obj->HandleKeyPress( &blockObj->corners,  keyEvent->key(), _FinishedBlocksContainer);

        return true;
    }

   else
   {
        // standard event processing
        return QObject::eventFilter(obj, event);
   }
}

void game::OnTimerTimeOut()
{
    qDebug()<<"Timeout";
    qDebug()<<" Corner 1 Now is: "<<blockObj->corners.corner1.x << ", " << blockObj->corners.corner1.y;
    MoveBlockWithTime();



}

void game::OnblockStopped()
{
    _FinishedBlocksContainer.push_back(&blockObj->corners);
    CreateBlock();
    qDebug()<<"Pushed a block in container";


}


void game::_UpdateWindow()
{
    //paint tetris blocks
    GlWindow_obj->SetOpenGlBuffer(_NewBlocksContainer);
     GlWindow_obj->PaintTetrisScreen();

}

void game::MoveBlockWithTime()
{

    if(_collisionDetector.CheckGameBottomBorder(_FinishedBlocksContainer, &blockObj->corners))
    {

        emit blockStopped();
        return;
    }
    blockObj->corners.corner1.y -= static_cast<float>(2.0f * windowGridUnitY);
    blockObj->corners.corner2.y -= static_cast<float>(2.0f * windowGridUnitY);

    blockObj->corners.corner3.y -= static_cast<float>(2.0f * windowGridUnitY);
    blockObj->corners.corner4.y -= static_cast<float>(2.0f * windowGridUnitY);

}

void game::CreateBlock()
{
     qDebug()<<"Created a new shape";
    blockObj= new TetrisShape;

   //create a tetris block
   square block(2.0f * windowGridUnitY, 2.0f *  windowGridUnitX);

   point startPosition;
   startPosition.x = -1.0f * windowGridUnitX;
   startPosition.y = 1.0f;

   randomize randomObject;
   RGBColor color = randomObject.getRandomColor();


   //create shape
   blockObj->CreateShape(block, startPosition, color);

   //insert shape in container
   _NewBlocksContainer.push_back(blockObj);

   _UpdateWindow();


}


