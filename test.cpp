// Модуль тестирования

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "globalmap.h"
#include <unistd.h>

int bigMapSize = 10;
int WALL;

int heroCoordX;
int heroCoordY;
int UNKNOWN;
int VISIBLE;
int wasThere;

int** map0;

void glutInits();
void display();
void getInitParams();

globalMap GM(10,5);



TEST_CASE( "First_use", "[test]" ) {

    // Инициализация GLUT и основных параметров карты
    glutInits();
    getInitParams();

    // Инициализация динамического двумерного массива карты
    map0 = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        map0[i] = new int[bigMapSize];
    }
    // Задание всех клеток изначально видимыми
    for(int i = 0; i < bigMapSize; i++){
        for(int j = 0; j < bigMapSize; j++){
            map0[i][j] = VISIBLE;
        }
    }
    // Создание стенок по граниам карты
    for (int i = 0; i < bigMapSize; ++i)
    {
        map0[i][0] = WALL;
        map0[0][i] = WALL;
        map0[i][bigMapSize - 1] = WALL;
        map0[bigMapSize - 1][i] = WALL;
    }
    // Задание координат героя
    heroCoordX = 5;
    heroCoordY = 5;
    GM.setHeroCoordXY(heroCoordX, heroCoordY);

    // Задание стенок снизу и сверху от героя
    map0[5][4] = WALL;
    map0[5][6] = WALL;

    // Синзронизация только что созданной карты с объектом
    GM.setGlobalMap(map0);

    // Получем карту с объекта
    map0 = GM.getCurrentMap();

    // Проверяем местонахождение героя
    CHECK(GM.getHeroCoordX() == 5);
    CHECK(GM.getHeroCoordY() == 5);

    // Проверяем наличие стенок снизу и сверху
    CHECK(map0[5][4] == WALL);
    CHECK(map0[5][6]  == WALL);

    // Проверяем наличие невидимых зон за стенками сверху
    CHECK(map0[5][3] == UNKNOWN);
    CHECK(map0[6][3] == UNKNOWN);
    CHECK(map0[4][3] == UNKNOWN);

    // Проверяем наличие невидимых зон за стенками снизу
    CHECK(map0[5][7] == UNKNOWN);
    CHECK(map0[4][7] == UNKNOWN);
    CHECK(map0[6][7] == UNKNOWN);

    display();
    usleep(1000000);

    // Идем вправо
    GM.goRight();
    display();
    usleep(1000000);

    // Идем вверх на 2 клетки
    GM.goUp();
    GM.goUp();
//    GM.goDown();
//    GM.goDown();
    display();
    usleep(1000000);

    // Верхние ячейки, которые были невидимы в начальном положении героя,
    // теперь должны стать видимыми
    // Проверяем это
    CHECK(map0[5][3] == VISIBLE);
    CHECK(map0[6][3] == VISIBLE);
    CHECK(map0[4][3] == VISIBLE);

    display();
    usleep(3000000);
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
    WALL = GM.getWALL();
    UNKNOWN = GM.getUNKNOWN();
    VISIBLE = GM.getVISIBLE();
    wasThere = GM.getWasThere();

}
