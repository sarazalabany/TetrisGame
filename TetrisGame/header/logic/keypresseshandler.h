#ifndef KEYPRESSESHANDLER_H
#define KEYPRESSESHANDLER_H

#include <QObject>
#include <QWidget>
#include "shapeDim.h"
#include "collisiondetector.h"

#include <QEvent>
#include <QKeyEvent>

class KeyPressesHandler : public QWidget
{
    Q_OBJECT
public:
    explicit KeyPressesHandler(QObject *parent = nullptr);

    void HandleKeyPress(squareCorners *corners, int keyPress, QVector<squareCorners*> existingBlocksContainer);


private:
    void DownKeyPressed(squareCorners *corners);
    void UpKeyPressed(squareCorners *corners);
    void LeftKeyPressed(squareCorners *corners);
    void RightKeyPressed(squareCorners *corners);

    squareCorners *_corners;
    CollisionDetector_C _collisionDetector;
    QVector<squareCorners*> _existingBlocksContainer;
};


#endif // KEYPRESSESHANDLER_H
