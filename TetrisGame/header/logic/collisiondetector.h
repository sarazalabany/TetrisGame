#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "globals.h"
#include "shapeDim.h"
#include <QVector>
#include <algorithm>

class CollisionDetector_C
{
public:
    CollisionDetector_C();

    bool CheckGameleftBorder(QVector<SquareCorners_C*> existingBlocks, SquareCorners_C* blockCorners);
    bool CheckGameRightSideBorder(QVector<SquareCorners_C*> existingBlocks, SquareCorners_C* blockCorners);
    bool CheckGameTopBorder(QVector<SquareCorners_C*> existingBlocks, SquareCorners_C* blockCorners);
    bool CheckGameBottomBorder(QVector<SquareCorners_C*> existingBlocks, SquareCorners_C* blockCorners);

private:
    bool CompareBlockBottomWithExistingBlocks(SquareCorners_C *block1, SquareCorners_C *existingBlock);

    bool CompareBlockTopWithExistingBlocks(SquareCorners_C *block1, SquareCorners_C *existingBlock);
    bool CompareBlockRightSideWithExistingBlocks(SquareCorners_C *block1, SquareCorners_C *existingBlock);
    bool CompareBlockLeftSideWithExistingBlocks(SquareCorners_C *block1, SquareCorners_C *existingBlock);

};

#endif // COLLISIONDETECTOR_H
