// Модуль тестирования

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "globalmap.h"
#include <unistd.h>


int bigMapSize;
int WALL;

int heroCoordX;
int heroCoordY;
int exitCoordX;
int exitCoordY;
int UNKNOWN;
int VISIBLE;
int wasThere;

int** map0;

void glutInits();
void display();
void getInitParams();

globalMap GM;


TEST_CASE( "First_use", "[test]" ) {

    // Инициализация GLUT и основных параметров карты
    glutInits();
    getInitParams();
    // Инициализация глобальной карты
    GM.setGlobalMap();
    while(1){
        // Проверяем наличие стенок  и невидимых зон в локальной карте
        GM.isFindWALL();
        // Рисуем текущую карту
        map0 = GM.getCurrentMap();
        display();

        char ch = ' ';
        cout << "Input ch" << endl;
        cin >> ch;

        int x = GM.getHeroCoordX();
        int y = GM.getHeroCoordY();
        switch(ch){
        case 'w':{
            CHECK ( GM.currentMap[x][--y] == VISIBLE );

            GM.goUp();
//             x = GM.getHeroCoordX();
//             y = GM.getHeroCoordY();
//              GM.isFindWALL();
             map0 = GM.getCurrentMap();

            display();


            CHECK ( map0[x][++y] == wasThere );
            break;
        }
        case 'a':{
            CHECK ( map0[--x][y] == VISIBLE );

            GM.goLeft();
//            x = GM.getHeroCoordX();
//            y = GM.getHeroCoordY();
//             GM.isFindWALL();
            map0 = GM.getCurrentMap();

            display();


            CHECK ( map0[++x][y] == wasThere );
            break;
        }
        case 's':{
            CHECK ( map0[x][++y] == VISIBLE );

            GM.goDown();
//            x = GM.getHeroCoordX();
//            y = GM.getHeroCoordY();
//             GM.isFindWALL();
            map0 = GM.getCurrentMap();

            display();


            CHECK (map0[x][--y] == wasThere );
            break; }
        case 'd':{
            CHECK ( map0[++x][y] == VISIBLE );

            GM.goRight();
//            x = GM.getHeroCoordX();
//            y = GM.getHeroCoordY();
//             GM.isFindWALL();
            map0 = GM.getCurrentMap();

            display();


            CHECK ( GM.currentMap[--x][y] == wasThere );
            break;  }
        }


//        int x = heroCoordX;
//        int y = heroCoordY;
//        CHECK ( GM.currentMap[x++][y] == VISIBLE );
//        CHECK ( GM.currentMap[x--][y] == VISIBLE );
//        CHECK ( GM.currentMap[x][y++] == VISIBLE );
//        CHECK ( GM.currentMap[x][y--] == VISIBLE );
    }

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
            else if (map0[i][j] == wasThere)
                glColor3f( 1, 0, 0);
            else if (map0[i][j] == WALL)
                glColor3f(0, 0, 0);
            else if (map0[i][j] == VISIBLE)
                glColor3f(1, 1, 1);
            else if (map0[i][j] == UNKNOWN)
                glColor3f( 0.64,  0.64, 0.64);

            glVertex2f((i) * 480 / bigMapSize, (j) * 480 / bigMapSize);
            glVertex2f((i + 1) * 480 / bigMapSize, (j) * 480 / bigMapSize);
            glVertex2f((i + 1) * 480 / bigMapSize, (j + 1) * 480 / bigMapSize);
            glVertex2f((i) * 480 / bigMapSize, (j + 1) * 480 / bigMapSize);
        }

    glEnd();
    glutSwapBuffers();
}

void glutInits(){

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
    WALL = GM.getWALL();
    heroCoordX = GM.getHeroCoordX();
    heroCoordY = GM.getHeroCoordY();

    exitCoordX = GM.getExitCoordX();
    exitCoordY = GM.getExitCoordY();
    UNKNOWN = GM.getUNKNOWN();
    VISIBLE = GM.getVISIBLE();
    wasThere = GM.getWasThere();

}
