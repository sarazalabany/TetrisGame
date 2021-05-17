#include "startgamewindow.h"
#include "ui_startgamewindowui.h"
#include <QDebug>

StartGameWindow_C::StartGameWindow_C(QMainWindow *parent) :
    ui(new Ui::StartGameWindow_C)
{
    ui->setupUi(parent);
    connect(ui->pushButton, &QPushButton::clicked, this, &StartGameWindow_C::OnPushButtonClicked);
}

StartGameWindow_C::~StartGameWindow_C()
{
    delete ui;
}


void StartGameWindow_C::OnPushButtonClicked()
{
    qDebug()<<"button clicked";
    emit startGameButtonPressed();
}
