#include "display.h"

Display::Display()
{
    int argc = 0;
    char* argv[1];
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(20, 1050 - 480 - 20);
    glutCreateWindow("Sample Algorithm");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, 480, 480, 0, -1, 1);
}

void Display::display(OpenMap* OM){

    heroCoordX = OM->getHeroCoordX();
    heroCoordY = OM->getHeroCoordY();
    map = OM->getMap();

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < OM->getSize(); ++i)
        for (int j = 0; j < OM->getSize(); ++j)
        {
            if ((i == heroCoordX)&&(j == heroCoordY))
                glColor3f(0, 0, 1);
            else if (map[i][j] == OM->getWasThere())
                glColor3f( 1, 0, 0);
            else if (map[i][j] == OM->getWALL())
                glColor3f(0, 0, 0);
            else if (map[i][j] == OM->getVISIBLE())
                glColor3f(1, 1, 1);
            else if (map[i][j] == OM->getEXIT())
                glColor3f( 1,  0, 1);
            else if (map[i][j] == OM->getUNKNOWN())
                glColor3f( 0.64,  0.64, 0.64);


            glVertex2f((i) * 480 / OM->getSize(), (j) * 480 / OM->getSize());
            glVertex2f((i + 1) * 480 / OM->getSize(), (j) * 480 / OM->getSize());
            glVertex2f((i + 1) * 480 / OM->getSize(), (j + 1) * 480 / OM->getSize());
            glVertex2f((i) * 480 / OM->getSize(), (j + 1) * 480 / OM->getSize());
        }

    glEnd();
    glutSwapBuffers();
}
