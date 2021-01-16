#ifndef GAMEUI_H
#define GAMEUI_H

#include <QMainWindow>
#include "glwindow.h"


namespace Ui {
class GameUi;
}

class GameUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameUi(QWidget *parent=nullptr);
    ~GameUi();

    void DisplayGame();
    void InitGameWindow(GlWindow *glWindow_ptr);
private:
    Ui::GameUi *ui;
    GlWindow *glWindow;

};

#endif // GAMEUI_H
