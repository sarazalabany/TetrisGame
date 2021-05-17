#ifndef KEYPRESSESHANDLER_H
#define KEYPRESSESHANDLER_H

#include <QObject>
#include <QWidget>
#include "shapeDim.h"
#include "collisiondetector.h"

#include <QEvent>
#include <QKeyEvent>

class KeyPressesHandler_C : public QWidget
{
    Q_OBJECT
public:
    explicit KeyPressesHandler_C(QObject *parent = nullptr);

    void HandleKeyPress(SquareCorners_C *corners, int keyPress, QVector<SquareCorners_C*> existingBlocksContainer);


private:
    void DownKeyPressed(SquareCorners_C *corners);
    void UpKeyPressed(SquareCorners_C *corners);
    void LeftKeyPressed(SquareCorners_C *corners);
    void RightKeyPressed(SquareCorners_C *corners);

    SquareCorners_C *_corners;
    CollisionDetector_C _collisionDetector;
    QVector<SquareCorners_C*> _existingBlocksContainer;
};


#endif // KEYPRESSESHANDLER_H
