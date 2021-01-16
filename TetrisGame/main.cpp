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


//    //Game Loop

    GameUi *gameWindow =  new GameUi;
//    gameWindow->show();


    game *gameInstance = new game(gameWindow);
    gameInstance->InitGame();
    gameInstance->StartGame();

    return a.exec();
}
