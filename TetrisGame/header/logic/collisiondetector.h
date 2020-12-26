#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "globals.h"
#include "shapeDim.h"
#include <QVector>
#include <algorithm>

class CollisionDetector
{
public:
    CollisionDetector();

    bool CheckGameleftBorder(QVector<squareCorners*> existingBlocks, squareCorners* blockCorners);
    bool CheckGameRightSideBorder(QVector<squareCorners*> existingBlocks, squareCorners* blockCorners);
    bool CheckGameTopBorder(QVector<squareCorners*> existingBlocks, squareCorners* blockCorners);
    bool CheckGameBottomBorder(QVector<squareCorners*> existingBlocks, squareCorners* blockCorners);

private:
};

#endif // COLLISIONDETECTOR_H
