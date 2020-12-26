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

    point start;
    squareCorners corners;
    RGBColor blockColor;

    void CreateShape(square block, point startingPos, RGBColor color);

private:


};

#endif // TETRISSHAPE_H
