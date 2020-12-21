#include "glwindow.h"


GlWindow::GlWindow( QWidget* parent) {

}

GlWindow::~GlWindow() {}


void GlWindow::Init()
{
    initalizeGl();

}

void GlWindow::PaintTetrisShape(QVector<TetrisShape*> container)
{
    _shapeContainer = container;
    paintGL();
}


void GlWindow::initalizeGl()
{
    initializeOpenGLFunctions();
}

void GlWindow::resizeGL(int width, int height)
{

}

void GlWindow::paintGL()
{
    update();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glDisable(GL_DEPTH_TEST); //disable 3d buffer
    glClear(GL_COLOR_BUFFER_BIT); //cleans the screen



    for(auto shape : _shapeContainer)
    {
        glBegin(GL_QUADS);

         //first corner
         glColor3f(shape->blockColor.red,
                   shape->blockColor.green,
                   shape->blockColor.blue
                   );
         glVertex2f(shape->corners.corner1.x, shape->corners.corner1.y);

         //second corner
         glColor3f(shape->blockColor.red,
                   shape->blockColor.green,
                   shape->blockColor.blue
                   );
         glVertex2f(shape->corners.corner2.x, shape->corners.corner2.y);

         //third corner
         glColor3f(shape->blockColor.red,
                   shape->blockColor.green,
                   shape->blockColor.blue
                   );
         glVertex2f(shape->corners.corner3.x, shape->corners.corner3.y);

         //fourth corner
         glColor3f(shape->blockColor.red,
                   shape->blockColor.green,
                   shape->blockColor.blue
                   );
         glVertex2f(shape->corners.corner4.x, shape->corners.corner4.y);

         glEnd();
    }


    glFlush();
}
