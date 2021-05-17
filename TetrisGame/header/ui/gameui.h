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

    void SetWindow(QWidget* widget);

private:
    Ui::GameUi *ui;
};



#endif // GAMEUI_H
