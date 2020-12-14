#ifndef GLWINDOW_H
#define GLWINDOW_H


#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

#include "globals.h"
#include "shapeDim.h"
#include "tetrisshape.h"

//for handling key presses
#include "keypresseshandler.h"

class GlWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
        Q_OBJECT

    public:
        GlWindow(QWidget *parent = nullptr);
        ~GlWindow();

        void Init();
        void PaintTetrisShape(TetrisShape *TetrisShape);

        bool event(QEvent *evnt) override;

        //handle keypresses event
        void keyPressEvent(QKeyEvent *event) override;
    private:
        TetrisShape *shape;
        KeyPressesHandler KeyPressesHandler;
         void initalizeGl();


    protected:
        void resizeGL(int width, int height) override;
        void paintGL() override;
};
#endif // GLWINDOW_H
