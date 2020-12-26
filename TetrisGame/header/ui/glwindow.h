#ifndef GLWINDOW_H
#define GLWINDOW_H


#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QDebug>
#include "globals.h"
#include "shapeDim.h"
#include "tetrisshape.h"


class GlWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
        Q_OBJECT

    public:
        GlWindow(QWidget *parent = nullptr);
        ~GlWindow();

        void Init();
        void PaintTetrisShape(QVector<TetrisShape*> container);

    private:
        void initalizeGl();

        TetrisShape *shape;
        QVector<TetrisShape*> _shapeContainer;


    protected:
        void resizeGL(int width, int height) override;
        void paintGL() override;

};
#endif // GLWINDOW_H
