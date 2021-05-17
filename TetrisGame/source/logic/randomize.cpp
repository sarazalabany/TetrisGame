#include "randomize.h"

Randomize_C::Randomize_C()
{

}

RGBColor_C Randomize_C::getRandomColor()
{
    RGBColor_C color;
    color.red  = static_cast<float> (rand()) / RAND_MAX;
    color.blue = static_cast<float> (rand()) / RAND_MAX;
    color.green = static_cast<float> (rand()) / RAND_MAX;

    return color;
}

SquareCorners_C Randomize_C::getRandomShapeCoordinates()
{
    SquareCorners_C corners;
    return corners;

}
