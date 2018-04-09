#include "globalmap.h"
#include <unistd.h>


int bigMapSize;
int localMapSize;
int WALL;

int heroCoordX;
int heroCoordY;
int exitCoordX;
int exitCoordY;
int UNKNOWN;
int VISIBLE;
int wasThere;

int** map;
int** localMap;

void glutInit();
void display();
void getInitParams();

vector<int> pathX;
vector<int> pathY;

globalMap GM(10, 5);

int main()
{
    // Инициализация GLUT и основных параметров карты
    glutInit();
    getInitParams();
    // Инициализация глобальной карты
    GM.setGlobalMap();

    // Проверяем наличие стенок  и невидимых зон в локальной карте
    GM.isFindWALL();

    // Рисуем текущую карту
    map = GM.getCurrentMap();
    display();

    while(1){
        char ch;
        cin >> ch;
        switch(ch){
        case 'w': { GM.goUp();
            map = GM.getCurrentMap();
            display();
            break;}
        case 'a': { GM.goLeft();
            map = GM.getCurrentMap();
            display();
            break;}
        case 's': { GM.goDown();
            map = GM.getCurrentMap();
            display();
            break;}
        case 'd': { GM.goRight();
            map = GM.getCurrentMap();
            display();
            break;}
        }

    }

    glutMainLoop();
    return 0;
}
void display(){

    heroCoordX = GM.getHeroCoordX();
    heroCoordY = GM.getHeroCoordY();

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
        {
            if ((i == heroCoordX)&&(j == heroCoordY))
                glColor3f(0, 0, 1);
            else  if ((i == exitCoordX)&&(j == exitCoordY))
                glColor3f(1, 1, 0);
            else if (map[i][j] == wasThere)
                glColor3f( 1, 0, 0);
            else if (map[i][j] == WALL)
                glColor3f(0, 0, 0);
            else if (map[i][j] == VISIBLE)
                glColor3f(1, 1, 1);
            else if (map[i][j] == UNKNOWN)
                glColor3f( 0.64,  0.64, 0.64);

            //            else
            //                glColor3f(1, 1, 1);




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
    bigMapSize = GM.getBigMapSize();
    localMapSize = GM.getLocalMapSize();
    WALL = GM.getWALL();
    heroCoordX = GM.getHeroCoordX();
    heroCoordY = GM.getHeroCoordY();

    UNKNOWN = GM.getUNKNOWN();
    VISIBLE = GM.getVISIBLE();
    wasThere = GM.getWasThere();

}
