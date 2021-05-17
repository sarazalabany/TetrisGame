#include "gameui.h"
#include "ui_gameui.h"

GameUi_C::GameUi_C(QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::GameUi)
{
    ui->setupUi(this);


}

void GameUi_C::InitGameWindow(GlWindow_C *glWindow_ptr)
{
    _glWindow = glWindow_ptr;
    ui->TetrisScreen->addWidget(_glWindow);

    _glWindow->show(); //show should be called first because i think thsi is what makes opengl context
    _glWindow->Init();


}

void GameUi_C::DisplayGame()
{
    _glWindow->PaintTetrisScreen();
}
GameUi_C::~GameUi_C()
{

    delete ui;
}
