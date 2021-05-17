#ifndef GLWINDOW_H
#define GLWINDOW_H


#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QDebug>
#include "globals.h"
#include "shapeDim.h"
#include "tetrisshape.h"


class GlWindow_C : public QOpenGLWidget, protected QOpenGLFunctions
{
        Q_OBJECT

    public:
        GlWindow_C(QWidget *parent = nullptr);
        ~GlWindow_C();

        void Init();
        void SetOpenGlBuffer(QVector<TetrisShape_C*> container);
        void PaintTetrisScreen();

    private:

        TetrisShape_C *shape;
        QVector<TetrisShape_C*> _shapeContainer;

    protected:
        void resizeGL(int width, int height) override;
        void paintGL() override;
        void initializeGL() override;

};
#endif // GLWINDOW_H
