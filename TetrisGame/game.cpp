#include "game.h"
#include <QTimer>


game::game()
{
    GlWindow_obj = new GlWindow;
}

void game::InitGame()
{

    GlWindow_obj->setTitle("openGL Window");
    GlWindow_obj->resize(window_width,window_length);
    GlWindow_obj->show();
    GlWindow_obj->Init();

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

    qDebug()<<"Size of _NewBlocksContainer vector is "<<_NewBlocksContainer.size();
}


void game::StopGame()
{

}

void game::SetGameSpeed(int speed)
{
    GameSpeed = speed;
}

void game::OnTimerTimeOut()
{
    qDebug()<<"Timeout";
    qDebug()<<" Corner 1 Now is: "<<blockObj->corners.corner1.x << ", " << blockObj->corners.corner1.y;
    MoveBlockWithTime();



}

void game::OnblockStopped()
{
    //_BlocksContainer.push_back(blockObj);
    CreateBlock();
    qDebug()<<"Pushed a block in container";


}

bool game::event(QEvent* event) //this is the more general case
{
    if (event->type() == QEvent::KeyPress) {
           QKeyEvent *ke = static_cast<QKeyEvent *>(event);
           if (ke->key() == 'A')  //if the key is A i will handle it
           {
              qDebug()<<"A button pressed";
               return true;
           }
        //return KeyPressesHandler::event(QEvent::KeyPress);
       }
    return QWidget::event(event); //everthing else gets handled by the default QWidget, and since I only have QOpenGLWindow
}

void game::keyPressEvent(QKeyEvent* event) //every key press wil be handeld here
{
    qDebug()<<"pressed key" << static_cast<int> (event->key());


    //TODO: convert this to a switch case
    if (static_cast<int> (event->key()) == DOWN_KEY )
    {
        KeyPressesHandler.DownKeyPressed(&blockObj->corners);

    }

    else if (static_cast<int> (event->key()) ==  LEFT_KEY )
    {
        KeyPressesHandler.LeftKeyPressed(&blockObj->corners);

        qDebug()<<" Corner after press is: "<<blockObj->corners.corner1.x << ", " << blockObj->corners.corner1.y;

    }

    else if (static_cast<int> (event->key()) ==  RIGHT_KEY )
    {
        KeyPressesHandler.RightKeyPressed(&blockObj->corners);
    }

}

void game::MoveBlockWithTime()
{

    if(_collisionDetector.CheckGameBottomBorder(&blockObj->corners))
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

   //set block color
   RGBColor lightBlue(0.3f, 0.78f, 0.74f);


   //create shape
   blockObj->CreateShape(block, startPosition, lightBlue);

   //insert shape in container
   _NewBlocksContainer.push_back(blockObj);

   //set current shape pointer

   //paint tetris blocks
   GlWindow_obj->PaintTetrisShape(_NewBlocksContainer);
}


