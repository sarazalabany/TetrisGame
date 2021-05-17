#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "randomize.h"

class Shape2D_C
{
public:
    Shape2D_C();

    void CreateShape();
    RGBColor_C GetColor();
    SquareCorners_C GetCorners();

private:
    float _width, _length;
    RGBColor_C _color;
    SquareCorners_C _corners;

    Randomize_C _randomHandler;

};

#endif // SHAPE2D_H
