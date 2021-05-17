#include "collisiondetector.h"
#include "QDebug"

CollisionDetector_C::CollisionDetector_C()
{

}

bool CollisionDetector_C::CheckGameleftBorder(QVector<SquareCorners_C*> existingBlocks, SquareCorners_C *blockCorners)
{
    bool leftSideBorderCrash = false;

   if(blockCorners->corner1.x  < xMinCoordinate)
   {
       //reached min
       leftSideBorderCrash = true;
   }

   return leftSideBorderCrash;

}
bool CollisionDetector_C::CheckGameRightSideBorder(QVector<SquareCorners_C*> existingBlocks, SquareCorners_C *blockCorners)
{
    bool rightSideBorderCrash = false;
    if(blockCorners->corner2.x > xMaxCoordinate)
    {
        //reached max
        rightSideBorderCrash = true;
    }
    return rightSideBorderCrash;
}

bool CollisionDetector_C::CheckGameTopBorder(QVector<SquareCorners_C*> existingBlocks, SquareCorners_C *blockCorners)
{
    bool TopBorderCrash = false;
    if(blockCorners->corner1.y > yMaxCoordinate)
    {
        //reached max
        TopBorderCrash = true;
    }

   return TopBorderCrash;

}

bool CollisionDetector_C::CheckGameBottomBorder(QVector<SquareCorners_C*> existingBlocks, SquareCorners_C *blockCorners)
{
    bool BottomBorderCrash = false;

    if(blockCorners->corner3.y < yMinCoordinate)
    {
        qDebug()<<"now is"<< blockCorners->corner3.y;
        //reached min
        BottomBorderCrash = true;
        return BottomBorderCrash;
    }

    if(!existingBlocks.isEmpty())
    {
        for(auto block: existingBlocks)
        {
            qDebug()<<"existing block has " << block->corner1.y;

            if(blockCorners->corner3.y == block->corner1.y)
            {
                BottomBorderCrash = true;
                return BottomBorderCrash;
            }
        }
    }

    return BottomBorderCrash;

}

