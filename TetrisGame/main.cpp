#include "mainwindow.h"

#include <QApplication>

#include "tetrisshape.h"
#include "glwindow.h"
#include "globals.h"

#include <QDebug>
#include <QDesktopWidget>
#include "game.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Game Loop

    game gameInstance;
    gameInstance.InitGame();
    gameInstance.StartGame();


    return a.exec();
}
