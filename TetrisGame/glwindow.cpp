#include "glwindow.h"


GlWindow::GlWindow(QWidget* parent) {

}

GlWindow::~GlWindow() {}


void GlWindow::Init()
{
    initalizeGl();

}

void GlWindow::PaintTetrisShape(TetrisShape *TetrisShape)
{
    shape = TetrisShape;
    paintGL();
}



void GlWindow::keyPressEvent(QKeyEvent* event) //every key press wil be handeld here
{
    //qDebug()<<"pressed key" << static_cast<int> (event->key());

    //TODO: convert this to a switch case
    if (static_cast<int> (event->key()) == DOWN_KEY )
    {
        KeyPressesHandler.DownKeyPressed(&shape->corners);

    }

    else if (static_cast<int> (event->key()) ==  LEFT_KEY )
    {
        KeyPressesHandler.LeftKeyPressed(&shape->corners);
    }

    else if (static_cast<int> (event->key()) ==  RIGHT_KEY )
    {
        KeyPressesHandler.RightKeyPressed(&shape->corners);
    }
    //1-check if button was pressed
    //2-Corners update
    //3-graphic update
    paintGL();

}


bool GlWindow::event(QEvent* event) //this is the more general case
{
    if (event->type() == QEvent::KeyPress) {
           QKeyEvent *ke = static_cast<QKeyEvent *>(event);
           if (ke->key() == 'A')  //if the key is A i will handle it
           {
              qDebug()<<"A button pressed";
               return true;
           }
//        return KeyPressesHandler::event(QEvent::KeyPress);
       }
    return QOpenGLWindow::event(event); //everthing else gets handled by the default QWidget, and since I only have QOpenGLWindow
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
    glFlush();
}
