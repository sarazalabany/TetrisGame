#include "collisiondetector.h"
#include "QDebug"

CollisionDetector::CollisionDetector()
{

}

bool CollisionDetector::CheckGameleftBorder(squareCorners *blockCorners)
{
    bool leftSideBorderCrash = false;

   if(blockCorners->corner1.x  < xMinCoordinate)
   {
       //reached min
       leftSideBorderCrash = true;
   }

   return leftSideBorderCrash;

}
bool CollisionDetector::CheckGameRightSideBorder(squareCorners *blockCorners)
{
    bool rightSideBorderCrash = false;
    if(blockCorners->corner2.x > xMaxCoordinate)
    {
        //reached max
        rightSideBorderCrash = true;
    }
    return rightSideBorderCrash;
}

bool CollisionDetector::CheckGameTopBorder(squareCorners *blockCorners)
{
    bool TopBorderCrash = false;
    if(blockCorners->corner1.y > yMaxCoordinate)
    {
        //reached max
        TopBorderCrash = true;
    }

   return TopBorderCrash;

}

bool CollisionDetector::CheckGameBottomBorder(squareCorners *blockCorners)
{
    bool BottomBorderCrash = false;
    if(blockCorners->corner3.y < yMinCoordinate)
    {
        qDebug()<<"now is"<< blockCorners->corner3.y;
        //reached min
        BottomBorderCrash = true;
    }
    return BottomBorderCrash;

}
