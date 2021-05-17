#include "tetrisshape.h"
#include <QDebug>

TetrisShape_C::TetrisShape_C()
{

}

//TetrisShape::TetrisShape(square block, point startingPos, RGBColor color)
//{
//    CreateShape(block, startingPos, color);
//}

void TetrisShape_C::CreateShape(Square_C block, Point_C startingPos, RGBColor_C color)
{
    //store the starting position lever of the block
    start.x = startingPos.x;
    start.y = startingPos.y;

    //first corner
    corners.corner1.x = start.x;
    corners.corner1.y = start.y;

    qDebug()<<" Corner 1: "<<corners.corner1.x << ", " << corners.corner1.y;

    //second corner
    corners.corner2.x = start.x + block.width;
    corners.corner2.y = start.y;

    qDebug()<<" Corner 2: "<<corners.corner2.x << ", " << corners.corner2.y;

    //third corner
    corners.corner3.x = start.x + block.width;
    corners.corner3.y = start.y - block.length;

    qDebug()<<" Corner 3: "<<corners.corner3.x << ", " << corners.corner3.y;

    //fourth corner
    corners.corner4.x = start.x;
    corners.corner4.y = start.y - block.length;

    qDebug()<<" Corner 4: "<<corners.corner4.x << ", " << corners.corner4.y;

    //color
    blockColor.red   = color.red;
    blockColor.green = color.green;
    blockColor.blue  = color.blue;

}
