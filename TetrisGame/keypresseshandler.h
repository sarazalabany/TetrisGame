#ifndef KEYPRESSESHANDLER_H
#define KEYPRESSESHANDLER_H

#include <QObject>
#include "shapeDim.h"
#include "collisiondetector.h"


class KeyPressesHandler : public QObject
{
    Q_OBJECT
public:
    explicit KeyPressesHandler(QObject *parent = nullptr);

    void DownKeyPressed(squareCorners *corners);
    void UpKeyPressed(squareCorners *corners);
    void LeftKeyPressed(squareCorners *corners);
    void RightKeyPressed(squareCorners *corners);


signals:

public slots:

private:


    CollisionDetector _collisionDetector;
};

#endif // KEYPRESSESHANDLER_H
