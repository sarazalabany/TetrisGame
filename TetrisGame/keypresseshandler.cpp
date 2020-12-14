#include "keypresseshandler.h"
#include "globals.h"

KeyPressesHandler::KeyPressesHandler(QObject *parent) : QObject(parent)
{

}


void KeyPressesHandler::DownKeyPressed(squareCorners *corners)
{
    if(_collisionDetector.CheckGameBottomBorder(corners))
    {
        return;
    }

    corners->corner1.y -= yMovementStepSize;
    corners->corner2.y -= yMovementStepSize;

    corners->corner3.y -= yMovementStepSize;
    corners->corner4.y -= yMovementStepSize;

}

void KeyPressesHandler::LeftKeyPressed(squareCorners *corners)
{
    if(_collisionDetector.CheckGameleftBorder(corners))
    {
        return;
    }
    corners->corner1.x -= xMovementStepSize;
    corners->corner2.x -= xMovementStepSize;

    corners->corner3.x -= xMovementStepSize;
    corners->corner4.x -= xMovementStepSize;
}

void KeyPressesHandler::RightKeyPressed(squareCorners *corners)
{
    if(_collisionDetector.CheckGameRightSideBorder(corners))
    {
        return;
    }
    corners->corner1.x += xMovementStepSize;
    corners->corner2.x += xMovementStepSize;

    corners->corner3.x += xMovementStepSize;
    corners->corner4.x += xMovementStepSize;

}

void KeyPressesHandler::UpKeyPressed(squareCorners *corners)
{
    corners->corner1.y += static_cast<float>(0.5);
    corners->corner2.y += static_cast<float>(0.5);

    corners->corner3.y += static_cast<float>(0.5);
    corners->corner4.y += static_cast<float>(0.5);

}

