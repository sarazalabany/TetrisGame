#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

class MainWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Init();

protected:
    void initalizeGl();
    void resizeGL(int width, int height);
    void paintGL();



};
#endif // MAINWINDOW_H
