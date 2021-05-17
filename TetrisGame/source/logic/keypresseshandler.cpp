#include "keypresseshandler.h"
#include "globals.h"
#include <QDebug>

KeyPressesHandler_C::KeyPressesHandler_C(QObject *parent)
{

}

 void KeyPressesHandler_C::HandleKeyPress(SquareCorners_C *corners, int keyPress, QVector<SquareCorners_C*> existingBlocksContainer)
{
        _existingBlocksContainer = existingBlocksContainer;

        if ( DOWN_KEY == keyPress)
        {
           DownKeyPressed(corners);


        }

        else if (LEFT_KEY == keyPress)
        {
           LeftKeyPressed(corners);

        }

        else if (RIGHT_KEY == keyPress)
        {
           RightKeyPressed(corners);
        }

}

void KeyPressesHandler_C::DownKeyPressed(SquareCorners_C *corners)
{
    if(_collisionDetector.CheckGameBottomBorder(_existingBlocksContainer, corners))
    {
        return;
    }

    corners->corner1.y -= yMovementStepSize;
    corners->corner2.y -= yMovementStepSize;

    corners->corner3.y -= yMovementStepSize;
    corners->corner4.y -= yMovementStepSize;

}

void KeyPressesHandler_C::LeftKeyPressed(SquareCorners_C *corners)
{
    if(_collisionDetector.CheckGameleftBorder(_existingBlocksContainer, corners))
    {
        return;
    }
    corners->corner1.x -= xMovementStepSize;
    corners->corner2.x -= xMovementStepSize;

    corners->corner3.x -= xMovementStepSize;
    corners->corner4.x -= xMovementStepSize;
}

void KeyPressesHandler_C::RightKeyPressed(SquareCorners_C *corners)
{
    if(_collisionDetector.CheckGameRightSideBorder(_existingBlocksContainer, corners))
    {
        return;
    }
    corners->corner1.x += xMovementStepSize;
    corners->corner2.x += xMovementStepSize;

    corners->corner3.x += xMovementStepSize;
    corners->corner4.x += xMovementStepSize;

}

void KeyPressesHandler_C::UpKeyPressed(SquareCorners_C *corners)
{
    corners->corner1.y += static_cast<float>(0.5);
    corners->corner2.y += static_cast<float>(0.5);

    corners->corner3.y += static_cast<float>(0.5);
    corners->corner4.y += static_cast<float>(0.5);

}

