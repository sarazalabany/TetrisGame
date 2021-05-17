#ifndef GAMEUI_H
#define GAMEUI_H

#include <QMainWindow>
#include "glwindow.h"


namespace Ui {
class GameUi;
}

class GameUi_C : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameUi_C(QWidget *parent=nullptr);
    ~GameUi_C();

    void DisplayGame();
    void InitGameWindow(GlWindow_C *glWindow_ptr);
private:
    Ui::GameUi *ui;
    GlWindow_C *_glWindow;

};

#endif // GAMEUI_H
