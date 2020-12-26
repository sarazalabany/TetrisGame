#ifndef RANDOMIZE_H
#define RANDOMIZE_H

#include "shapeDim.h"
#include "random"

class randomize
{
public:
    randomize();
    RGBColor getRandomColor();
    squareCorners getRandomShapeCoordinates();

};

#endif // RANDOMIZE_H
