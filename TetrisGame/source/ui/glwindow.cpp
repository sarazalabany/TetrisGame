#include "glwindow.h"


GlWindow_C::GlWindow_C( QWidget* parent) {
}

GlWindow_C::~GlWindow_C() {}


void GlWindow_C::Init()
{
    initializeGL();

}

void GlWindow_C::SetOpenGlBuffer(QVector<TetrisShape_C*> container)
{
    _shapeContainer = container;

}

void GlWindow_C::PaintTetrisScreen()
{
        paintGL();
}


void GlWindow_C::initializeGL()
{
    initializeOpenGLFunctions();
}

void GlWindow_C::resizeGL(int width, int height)
{

}

void GlWindow_C::paintGL()
{
    update();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glDisable(GL_DEPTH_TEST); //disable 3d buffer
    glClear(GL_COLOR_BUFFER_BIT); //cleans the screen

    for(auto shape : _shapeContainer)
    {

        glBegin(GL_QUADS);
        glColor3f(shape->block_color.red,
                  shape->block_color.green,
                  shape->block_color.blue
                  );
        glVertex2f(shape->corners.corner1.x, shape->corners.corner1.y);

        //second corner
        glVertex2f(shape->corners.corner2.x, shape->corners.corner2.y);

        //third corner
        glVertex2f(shape->corners.corner3.x, shape->corners.corner3.y);

        //fourth corner
        glVertex2f(shape->corners.corner4.x, shape->corners.corner4.y);

        glEnd();
    }


    glFlush();
}
