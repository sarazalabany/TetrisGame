#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "globals.h"
#include "shapeDim.h"

class CollisionDetector
{
public:
    CollisionDetector();




    bool CheckGameleftBorder(squareCorners* blockCorners);
    bool CheckGameRightSideBorder(squareCorners* blockCorners);
    bool CheckGameTopBorder(squareCorners* blockCorners);
    bool CheckGameBottomBorder(squareCorners* blockCorners);
private:
};

#endif // COLLISIONDETECTOR_H
