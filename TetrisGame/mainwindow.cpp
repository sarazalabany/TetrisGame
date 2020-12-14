#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{

}

MainWindow::~MainWindow()
{

}

void MainWindow::Init()
{
    initalizeGl();

}

void MainWindow::initalizeGl()
{
    initializeOpenGLFunctions();
            glClearColor(0,0,0,1);
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_LIGHT0);
            glEnable(GL_LIGHTING);
            glEnable(GL_COLOR_MATERIAL);

}

void MainWindow::resizeGL(int width, int height)
{

}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
