#include "tetrisshape.h"
#include <QDebug>

TetrisShape_C::TetrisShape_C()
{

}

//TetrisShape::TetrisShape(square block, point startingPos, RGBColor color)
//{
//    CreateShape(block, startingPos, color);
//}

void TetrisShape_C::CreateShape(Square_C block, Point_C start_position, RGBColor_C color)
{
    //store the starting position lever of the block
    start_position.x = start_position.x;
    start_position.y = start_position.y;

    //first corner
    corners.corner1.x = start_position.x;
    corners.corner1.y = start_position.y;

    //second corner
    corners.corner2.x = start_position.x + block.width;
    corners.corner2.y = start_position.y;

    //third corner
    corners.corner3.x = start_position.x + block.width;
    corners.corner3.y = start_position.y - block.length;

    //fourth corner
    corners.corner4.x = start_position.x;
    corners.corner4.y = start_position.y - block.length;

    block_color.red   = color.red;
    block_color.green = color.green;
    block_color.blue  = color.blue;

}
