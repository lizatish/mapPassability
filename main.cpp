#include <unistd.h>


int bigMapSize;
int WALL;

int heroCoordX;
int heroCoordY;

int UNKNOWN;
int VISIBLE;
int wasThere;

int** map;
int** localMap;

void glutInit();
void display();
void getInitParams();

#include "navigator.h"
#include "openmap.h"
#include "globalmap.h"
#include "localmap.h"

GlobalMap* GM;



int main()
{
    // Инициализация GLUT и основных параметров карты


    GM = new GlobalMap(20, 10, 10);
    GM->setGlobalMap();

    LocalMap* LM;
    LM = new LocalMap();
    int** localMap = LM->getMap();

    Navigator NTR(GM, LM);
    localMap = NTR.connectGlobalAndLocalMap(localMap);

    OpenMap* OM;
    OM = new OpenMap(GM);
    OM->connectOpenAndLocalMap(LM);
    map = OM->getMap();



    glutInit();
    getInitParams();
    display();
    usleep(300000);
    glutMainLoop();

    return 0;


}
void display(){

    heroCoordX = GM->getHeroCoordX();
    heroCoordY = GM->getHeroCoordY();

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
        {
            if ((i == heroCoordX)&&(j == heroCoordY))
                glColor3f(0, 0, 1);
            else if (map[i][j] == wasThere)
                glColor3f( 1, 0, 0);
            else if (map[i][j] == WALL)
                glColor3f(0, 0, 0);
            else if (map[i][j] == VISIBLE)
                glColor3f(1, 1, 1);
            else if (map[i][j] == UNKNOWN)
                glColor3f( 0.64,  0.64, 0.64);


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

void getInitParams(){
    bigMapSize = GM->getSize();
    WALL = GM->getWALL();
    heroCoordX = GM->getHeroCoordX();
    heroCoordY = GM->getHeroCoordY();

    UNKNOWN = GM->getUNKNOWN();
    VISIBLE = GM->getVISIBLE();
    wasThere = GM->getWasThere();

}

