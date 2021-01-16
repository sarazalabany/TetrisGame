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
    bool CompareBlockBottomWithExistingBlocks(squareCorners *block1, squareCorners *existingBlock);

    bool CompareBlockTopWithExistingBlocks(squareCorners *block1, squareCorners *existingBlock);
    bool CompareBlockRightSideWithExistingBlocks(squareCorners *block1, squareCorners *existingBlock);
    bool CompareBlockLeftSideWithExistingBlocks(squareCorners *block1, squareCorners *existingBlock);

};

#endif // COLLISIONDETECTOR_H
