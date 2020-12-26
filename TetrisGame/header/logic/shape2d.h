#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "randomize.h"

class Shape2D
{
public:
    Shape2D();

    void CreateShape();
    RGBColor GetColor();
    squareCorners GetCorners();

private:
    float width, length;
    RGBColor color;
    squareCorners corners;

    randomize _randomHandler;

};

#endif // SHAPE2D_H
