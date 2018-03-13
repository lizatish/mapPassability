#include "globalmap.h"

int bigMapSize;
int localMapSize;
int WALL;

int heroCoordX;
int heroCoordY;
int exitCoordX;
int exitCoordY;
int UNKNOWN;

int** map;
int** localMap;
void glutInit();
void display();

globalMap GM;

int main()
{

    glutInit();
    GM.setGlobalMap();
      GM.isFindWALL();


    bigMapSize = GM.getBigMapSize();
    localMapSize = GM.getLocalMapSize();
    WALL = GM.getWALL();
    heroCoordX = GM.getHeroCoordX();
    heroCoordY = GM.getHeroCoordY();

    exitCoordX = GM.getExitCoordX();
    exitCoordY = GM.getExitCoordY();
    UNKNOWN = GM.getUNKNOWN();


//    map = GM.getMap();
//    glutDisplayFunc(display);
    map = GM.getCurrentMap();
    glutDisplayFunc(display);

    glutMainLoop();


    return 0;
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
        {
            if ((i == heroCoordX)&&(j == heroCoordY))
                glColor3f(0, 0, 1);
            else  if ((i == exitCoordX)&&(j == exitCoordY))
                glColor3f(1, 1, 0);
            else if (map[i][j] == WALL)
                glColor3f(0, 0, 0);
            else if (map[i][j] == 0)
                glColor3f(1, 1, 1);
            else if (map[i][j] == -10)
                glColor3f(0.58, 0.53, 0.53);
            else if (map[i][j] == -20)
                glColor3f(0.06, 0.96, 0.92);
            else if (map[i][j] == UNKNOWN)
                glColor3f( 0.64,  0.64, 0.64);


            else
                glColor3f(map[i][j] / 48.0, 0, 0);

            glVertex2f((i) * 480 / bigMapSize, (j) * 480 / bigMapSize);
            glVertex2f((i + 1) * 480 / bigMapSize, (j) * 480 / bigMapSize);
            glVertex2f((i + 1) * 480 / bigMapSize, (j + 1) * 480 / bigMapSize);
            glVertex2f((i) * 480 / bigMapSize, (j + 1) * 480 / bigMapSize);
        }

    glEnd();
    glutSwapBuffers();
}

void glutInit(){

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
