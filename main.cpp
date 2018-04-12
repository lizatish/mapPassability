#include <unistd.h>


int bigMapSize;
int WALL;

int heroCoordX;
int heroCoordY;

int UNKNOWN;
int VISIBLE;
int WAS_THERE;
int** map;

void glutInit();
void display();
void getInitParams();

#include "navigator.h"
#include "openmap.h"
#include "globalmap.h"
#include "localmap.h"
#include <stdio.h>

GlobalMap* GM;
OpenMap* OM;


void goRight();
void goLeft();
void goDown();
void goUp();

int main()
{
    GM = new GlobalMap(20, 10, 10);
    GM->setGlobalMap();

    LocalMap* LM;
    LM = new LocalMap();
    int** localMap = LM->getMap();

    Navigator NTR(GM, LM);
    localMap = NTR.connectGlobalAndLocalMap(localMap);

    OM = new OpenMap(GM);
    OM->connectOpenAndLocalMap(LM);
    map = OM->getMap();

    // Инициализация GLUT и основных параметров карты
    glutInit();
    getInitParams();
    display();

    while(1){
        localMap = NTR.connectGlobalAndLocalMap(localMap);
        OM->connectOpenAndLocalMap(LM);
        map = OM->getMap();
        display();

        bool access = false;
        char ch;
        cin >> ch;
        switch(ch){
        case 'w': {
            access = OM->isFreeGoUp();
            if(access == true){
                OM->goUp();
                NTR.goUp();
            }
            break;}
        case 'a': {
            access =  OM->isFreeGoLeft();
            if(access == true){
                OM->goLeft();
                NTR.goLeft();
            }
            break;}
        case 's': {
            access = OM->isFreeGoDown();
            if(access == true){
                OM->goDown();
                NTR.goDown();
            }
            break;}
        case 'd': {
            access = OM->isFreeGoRight();
            if(access == true){
                OM->goRight();
                NTR.goRight();
            }
            break;
        }
        }
        //    OM->connectOpenAndLocalMap(LM);



    }

    glutMainLoop();
    return 0;
}

void display(){

    heroCoordX = OM->getHeroCoordX();
    heroCoordY = OM->getHeroCoordY();

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
        {
            if ((i == heroCoordX)&&(j == heroCoordY))
                glColor3f(0, 0, 1);
            else if (map[i][j] == WAS_THERE)
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
    WAS_THERE = GM->getWasThere();

}

