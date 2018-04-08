// Модуль тестирования

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
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

int** map0;
int** localMap;

void glutInits();
void display();
void getInitParams();

vector<int> pathX;
vector<int> pathY;

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
        switch(ch){
        case 'w':{ GM.goUp(); break; }
        case 'a':{ GM.goLeft();  break; }
        case 's':{ GM.goDown(); break; }
        case 'd':{ GM.goRight(); break; }
        }
        display();


        int x = heroCoordX;
        int y = heroCoordY;
        CHECK ( GM.currentMap[x++][y] == WALL );
        CHECK ( GM.currentMap[x--][y] == WALL );
        CHECK ( GM.currentMap[x][y++] == WALL );
        CHECK ( GM.currentMap[x][y--] == WALL );






    }

    //    // Верные
    //    CHECK ( GM1.getBigMapSize() == 50 );
    //    CHECK ( GM1.getLocalMapSize() == 7 );

    //    CHECK ( GM2.getBigMapSize() == 40 );
    //    CHECK ( GM2.getLocalMapSize() == 6 );

    //    CHECK ( GM3.getBigMapSize() == 30 );
    //    CHECK ( GM3.getLocalMapSize() == 5 );

    //    GM1.setHeroCoordXY(10, 10);
    //    GM2.setHeroCoordXY(5, 8);
    //    GM3.setHeroCoordXY(27, 17);

    //    CHECK ( GM1.getHeroCoordX() == 10 );
    //    CHECK ( GM1.getHeroCoordY() == 10 );

    //    CHECK ( GM2.getHeroCoordX() == 5 );
    //    CHECK ( GM2.getHeroCoordY() == 8 );

    //    CHECK ( GM3.getHeroCoordX() == 27 );
    //    CHECK ( GM3.getHeroCoordY() == 17 );


    //    // Неверные
    //    CHECK ( GM3.getBigMapSize() != 8 );
    //    CHECK ( GM3.getLocalMapSize() != 1 );

    //    CHECK ( GM1.getHeroCoordX() != 2 );
    //    CHECK ( GM1.getHeroCoordY() != 1 );

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
    localMapSize = GM.getLocalMapSize();
    WALL = GM.getWALL();
    heroCoordX = GM.getHeroCoordX();
    heroCoordY = GM.getHeroCoordY();

    exitCoordX = GM.getExitCoordX();
    exitCoordY = GM.getExitCoordY();
    UNKNOWN = GM.getUNKNOWN();
    VISIBLE = GM.getVISIBLE();
    wasThere = GM.getWasThere();

}
