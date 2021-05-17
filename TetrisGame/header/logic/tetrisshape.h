#ifndef TETRISSHAPE_H
#define TETRISSHAPE_H

#include <iostream>
#include "shapeDim.h"

//this only draws the shape
//what Patrick meant was that I create only a block/square and always add

//this class takes a tetris object and paints it on the screen

class TetrisShape
{
public:
    TetrisShape();
    //TetrisShape(square block, point startingPos, RGBColor color);

    float width;
    float length;

    Point_C start;
    SquareCorners_C corners;
    RGBColor_C blockColor;

    void CreateShape(Square_C block, Point_C startingPos, RGBColor_C color);

private:


};

#endif // TETRISSHAPE_H
