#include "gameui.h"
#include "ui_gameui.h"

GameUi::GameUi(QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::GameUi)
{
    ui->setupUi(this);


}

void GameUi::InitGameWindow(GlWindow *glWindow_ptr)
{
    glWindow = glWindow_ptr;
    ui->TetrisScreen->addWidget(glWindow);


    glWindow->show(); //show should be called first because i think thsi is what makes opengl context
    glWindow->Init();


}

void GameUi::DisplayGame()
{
    glWindow->PaintTetrisScreen();
}
GameUi::~GameUi()
{

    delete ui;
}
