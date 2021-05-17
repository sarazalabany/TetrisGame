#ifndef RANDOMIZE_H
#define RANDOMIZE_H

#include "shapeDim.h"
#include "random"

class Randomize_C
{
public:
    Randomize_C();
    RGBColor_C GetRandomColor();
    SquareCorners_C GetRandomShapeCoordinates();

};

#endif // RANDOMIZE_H
