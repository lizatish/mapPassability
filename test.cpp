// Модуль тестирования

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "robot.h"
#include "map.h"
#include "display.h"
#include "globalmap.h"
#include "navigator.h"


TEST_CASE( "First_use", "[test]" ) {

    int baseMapSize = 10;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////    Тест глобальной карты       ////////////////////
    ///////////////////////////////////////////////////////////////////////

    GlobalMap* BaseMap;
    BaseMap = new GlobalMap(baseMapSize);

    // Проверяем размер карты
    CHECK(BaseMap->getSize() == baseMapSize);

    int WALL = BaseMap->getWALL();
    int VISIBLE = BaseMap->getVISIBLE();
    int WAS_THERE = BaseMap->getWasThere();
    int UNKNOWN = BaseMap->getUNKNOWN();

    // Инициализация динамического двумерного массива карты
    int** myMap;
    myMap = new int* [baseMapSize];
    for(int i = 0; i < baseMapSize; i++){
        myMap[i] = new int[baseMapSize];
    }

    // Задание всех клеток изначально видимыми
    for(int i = 0; i < baseMapSize; i++){
        for(int j = 0; j < baseMapSize; j++){
            myMap[i][j] = VISIBLE;
        }
    }

    // Задание стенок в определенных местах карты
    myMap[5][4] = WALL;
    myMap[5][6] = WALL;

    BaseMap->setGlobalMap(myMap);
    myMap = BaseMap->getMap();

    // Проверяем наличие стенок в определенных местах
    CHECK(myMap[5][4] == WALL);
    CHECK(myMap[5][6] == WALL);

    /////////////////////////////////////////////////////////////////////////
    ///////////////////         Тест навигатора             /////////////////
    /////////////////////////////////////////////////////////////////////////

    // Создание навигатора
    Navigator* NV;
    NV = new Navigator(BaseMap);
    // Установить текущее местоположение
    NV->setCoordinates(1, 1);

    CHECK(NV->getHeroCoordX() == 1);
    CHECK(NV->getHeroCoordY() == 1);

    CHECK(NV->getGlobalMapSize() == baseMapSize);

    NV->goRight();
    CHECK(NV->getHeroCoordX() == 2);
    CHECK(NV->getHeroCoordY() == 1);

    NV->goLeft();
    CHECK(NV->getHeroCoordX() == 1);
    CHECK(NV->getHeroCoordY() == 1);

    NV->goDown();
    CHECK(NV->getHeroCoordX() == 1);
    CHECK(NV->getHeroCoordY() == 2);

    NV->goUp();
    CHECK(NV->getHeroCoordX() == 1);
    CHECK(NV->getHeroCoordY() == 1);

    /////////////////////////////////////////////////////////////////////////
    ///////////////////       Тест локальной карты          /////////////////
    /////////////////////////////////////////////////////////////////////////

    LocalMap* LM;
    LM = new LocalMap();

    int locMapSize = 5;
    CHECK(LM->getSize() == locMapSize);

    NV->setCoordinates(5, 5);
    LM = NV->findRobotOnGlobalMap();

    int** myLocMap = LM->getMap();

    LM->isExistUNKNOWNzones();

    CHECK(myLocMap[2][1] == WALL);

    CHECK(myLocMap[2][0] == UNKNOWN);
    CHECK(myLocMap[3][0] == UNKNOWN);
    CHECK(myLocMap[1][0] == UNKNOWN);

    CHECK(myLocMap[2][3] == WALL);

    CHECK(myLocMap[2][4] == UNKNOWN);
    CHECK(myLocMap[3][4] == UNKNOWN);
    CHECK(myLocMap[1][4] == UNKNOWN);



    /////////////////////////////////////////////////////////////////////////
    ///////////////////            Тест робота              /////////////////
    /////////////////////////////////////////////////////////////////////////

    // Создание робота
    Robot* robotic;
    // Загружаем в робота навигатор
    robotic = new Robot(NV);
    /////////////////////////////////////////////////////////////////////////
    ///////////////////        Тест открытой карты          /////////////////
    /////////////////////////////////////////////////////////////////////////

    OpenMap* OM;
    OM = new OpenMap(baseMapSize, NV->getHeroCoordX(), NV->getHeroCoordY());

    CHECK(OM->getSize() == baseMapSize);
    CHECK(OM->getHeroCoordX() == NV->getHeroCoordX());
    CHECK(OM->getHeroCoordY() == NV->getHeroCoordY());

    OM = robotic->showSituation();

    int** myOpenMap = OM->getMap();


    CHECK(myOpenMap[5][4] == WALL);

    CHECK(myOpenMap[5][3] == UNKNOWN);
    CHECK(myOpenMap[6][3] == UNKNOWN);
    CHECK(myOpenMap[4][3] == UNKNOWN);

    CHECK(myOpenMap[5][6] == WALL);

    CHECK(myOpenMap[5][7] == UNKNOWN);
    CHECK(myOpenMap[6][7] == UNKNOWN);
    CHECK(myOpenMap[4][7] == UNKNOWN);

    /////////////////////////////////////////////////////////////////////////
    ////        Тест на движение робота и нарисовку открытой карты       ////
    /////////////////////////////////////////////////////////////////////////


    bool access = false;
    access =  OM->isFreeGoRight();
    CHECK(access == true);

    access = OM->isFreeGoLeft();
    CHECK(access == true);

    access = OM->isFreeGoDown();
    CHECK(access == false);

    access = OM->isFreeGoUp();
    CHECK(access == false);



    robotic->goRight();
    CHECK(NV->getHeroCoordX() == 6);
    CHECK(NV->getHeroCoordY() == 5);

    robotic->goRight();
    CHECK(NV->getHeroCoordX() == 7);
    CHECK(NV->getHeroCoordY() == 5);


    robotic->goLeft();
    CHECK(NV->getHeroCoordX() == 6);
    CHECK(NV->getHeroCoordY() == 5);

    robotic->goDown();
    CHECK(NV->getHeroCoordX() == 6);
    CHECK(NV->getHeroCoordY() == 6);

    robotic->goUp();
    CHECK(NV->getHeroCoordX() == 6);
    CHECK(NV->getHeroCoordY() == 5);

    myOpenMap = OM->getMap();
    CHECK(myOpenMap[5][5] == WAS_THERE);
    CHECK(myOpenMap[6][5] == WAS_THERE);
    CHECK(myOpenMap[7][5] == WAS_THERE);
    CHECK(myOpenMap[6][6] == WAS_THERE);




    /////////////////////////////////////////////////////////////////////////
    ////        Тест на верное наложение локальной и открытой карт       ////
    /////////////////////////////////////////////////////////////////////////

    //    // Создание открытой карты
    //    OpenMap* OM;


    //    // Получение текущей открытой карты
    //    OM = robotic->showSituation();







    //    // Проверяем наличие невидимых зон за стенками сверху
    //    CHECK(map0[5][3] == UNKNOWN);
    //    CHECK(map0[6][3] == UNKNOWN);
    //    CHECK(map0[4][3] == UNKNOWN);

    //    // Проверяем наличие невидимых зон за стенками снизу
    //    CHECK(map0[5][7] == UNKNOWN);
    //    CHECK(map0[4][7] == UNKNOWN);
    //    CHECK(map0[6][7] == UNKNOWN);

    //    display();
    //    usleep(1000000);

    //    // Идем вправо
    //    GM.goRight();
    //    display();
    //    usleep(1000000);

    //    // Идем вверх на 2 клетки
    //    GM.goUp();
    //    GM.goUp();
    //    display();
    //    usleep(1000000);

    //    // Верхние ячейки, которые были невидимы в начальном положении героя,
    //    // теперь должны стать видимыми
    //    // Проверяем это
    //    CHECK(map0[5][3] == VISIBLE);
    //    CHECK(map0[6][3] == VISIBLE);
    //    CHECK(map0[4][3] == VISIBLE);

    //    // Теперь идем вниз к невидимым зонам
    //    GM.goDown();
    //    GM.goDown();
    //    GM.goDown();
    //    GM.goDown();

    //    // Нижние ячейки, которые были невидимы в начальном положении героя,
    //    // теперь должны стать видимыми
    //    // Проверяем это
    //    CHECK(map0[5][7] == VISIBLE);
    //    CHECK(map0[4][7] == VISIBLE);
    //    CHECK(map0[6][7] == VISIBLE);

    //    // Проверка на то, что мы запомнили ячейки, в которых уже были
    //    // Проверка на начальное положение героя
    //    CHECK(map0[5][5] == WAS_THERE);
    //    // Как мы ходили вниз
    //    CHECK(map0[6][6] == WAS_THERE);
    //    // Как мы ходили вверх
    //    CHECK(map0[6][4] == WAS_THERE);
    //    CHECK(map0[6][3] == WAS_THERE);
    //    // Проверка на то, где сейчас герой
    //    CHECK(GM.getHeroCoordX() == 6);
    //    CHECK(GM.getHeroCoordY() == 7);


}
