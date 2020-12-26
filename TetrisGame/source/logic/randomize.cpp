#include "randomize.h"

randomize::randomize()
{

}

RGBColor randomize::getRandomColor()
{
    RGBColor color;
    color.red  = static_cast<float> (rand()) / RAND_MAX;
    color.blue = static_cast<float> (rand()) / RAND_MAX;
    color.green = static_cast<float> (rand()) / RAND_MAX;

    return color;
}

squareCorners randomize::getRandomShapeCoordinates()
{
    squareCorners corners;
    return corners;

}
