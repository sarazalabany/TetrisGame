#include "shape2d.h"



Shape2D::Shape2D(GlWindow& GlWindow)
    :GlWindow_obj(GlWindow)
{

}

void Shape2D::CreateShape()
{


//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
//    glClear(GL_COLOR_BUFFER_BIT);

//        glBegin(GL_QUADS);
//        glColor3f(1.0f, 1.0f, 0.0f);
//             glVertex2f(-0.5f, -0.5f);    // x, y
//             glVertex2f( 0.5f, -0.5f);
//             glVertex2f( 0.5f,  0.5f);
//             glVertex2f(-0.5f,  0.5f);

//        glEnd();

//        glFlush();

    GlWindow_obj.Paint();
}


void Shape2D::DrawShapeOnWindow()
{
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

