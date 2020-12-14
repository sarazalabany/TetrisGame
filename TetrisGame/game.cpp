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
    SetGameSpeed(GAME_SPEED_8_HZ);

}


void game::AddBlockToContainer()
{

}

void game::StartGame()
{
     blockObj= new TetrisShape;
    //////////////////////////////////////////////////////
    //create a tetris block
    square block(2.0f * windowGridUnitY, 2.0f *  windowGridUnitX);

    point startPosition;
    startPosition.x = -1.0f * windowGridUnitX;
    startPosition.y = 1.0f;

    //set block color
    RGBColor lightBlue(0.3f, 0.78f, 0.74f);


    //create shape
    blockObj->CreateShape(block, startPosition, lightBlue);
    //start timer
    MoveBlockstimer->start(GameSpeed);

    ///////////////////////////////////////////////////////
    //print the shape
    GlWindow_obj->PaintTetrisShape(blockObj);


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

void game::MoveBlockWithTime()
{
    blockObj->corners.corner1.y -= static_cast<float>(2.0f * windowGridUnitY);
    blockObj->corners.corner2.y -= static_cast<float>(2.0f * windowGridUnitY);

    blockObj->corners.corner3.y -= static_cast<float>(2.0f * windowGridUnitY);
    blockObj->corners.corner4.y -= static_cast<float>(2.0f * windowGridUnitY);
}
