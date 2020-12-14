#include "keypresseshandler.h"
#include "globals.h"

KeyPressesHandler::KeyPressesHandler(QObject *parent) : QObject(parent)
{

}


void KeyPressesHandler::DownKeyPressed(squareCorners *corners)
{
    corners->corner1.y -= static_cast<float>(2.0f * windowGridUnitY);
    corners->corner2.y -= static_cast<float>(2.0f * windowGridUnitY);

    corners->corner3.y -= static_cast<float>(2.0f * windowGridUnitY);
    corners->corner4.y -= static_cast<float>(2.0f * windowGridUnitY);
}

void KeyPressesHandler::LeftKeyPressed(squareCorners *corners)
{
    corners->corner1.x -= static_cast<float>(2.0f * windowGridUnitY);
    corners->corner2.x -= static_cast<float>(2.0f * windowGridUnitY);

    corners->corner3.x -= static_cast<float>(2.0f * windowGridUnitY);
    corners->corner4.x -= static_cast<float>(2.0f * windowGridUnitY);
}

void KeyPressesHandler::RightKeyPressed(squareCorners *corners)
{
    corners->corner1.x += static_cast<float>(2.0f * windowGridUnitY);
    corners->corner2.x += static_cast<float>(2.0f * windowGridUnitY);

    corners->corner3.x += static_cast<float>(2.0f * windowGridUnitY);
    corners->corner4.x += static_cast<float>(2.0f * windowGridUnitY);

}

void KeyPressesHandler::UpKeyPressed(squareCorners *corners)
{
    corners->corner1.y += static_cast<float>(0.5);
    corners->corner2.y += static_cast<float>(0.5);

    corners->corner3.y += static_cast<float>(0.5);
    corners->corner4.y += static_cast<float>(0.5);

}
