#ifndef STARTGAMEWINDOW_H
#define STARTGAMEWINDOW_H

#include <QMainWindow>


/*
 *This class controlls the game start menu
 *
 *
 */
namespace Ui {
class StartGameWindow_C;
}

class StartGameWindow_C : public QWidget
{
    Q_OBJECT

public:
    explicit StartGameWindow_C(QMainWindow *parent = nullptr);
    ~StartGameWindow_C();

private:
    Ui::StartGameWindow_C *ui;
signals:
    void startGameButtonPressed();

public slots:
    void OnPushButtonClicked();
};

#endif // STARTGAMEWINDOW_H
