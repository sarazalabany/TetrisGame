#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "glwindow.h"

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QtOpenGL>

class Shape2D
{
public:
    Shape2D(GlWindow &GlWindow);
    void DrawShapeOnWindow();
    void CreateShape();
private:
    float width, length;
    QOpenGLContext *context;
    QOpenGLFunctions *openGLFunctions;

    GlWindow &GlWindow_obj;
};

#endif // SHAPE2D_H
