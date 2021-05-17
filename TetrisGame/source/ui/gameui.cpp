#include "gameui.h"
#include "ui_gameui.h"

GameUi_C::GameUi_C(QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::GameUi)
{
    ui->setupUi(this);

}

void GameUi_C::SetWindow(QWidget *widget)
{
    ui->TetrisScreen->addWidget(widget);
}

GameUi_C::~GameUi_C()
{

    delete ui;
}
