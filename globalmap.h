#ifndef GLOBALMAP_H
#define GLOBALMAP_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <GL/glut.h>
#include <chrono>
#include <thread>
#include <math.h>
#include <queue>
#include <ctime> // содержит time()
using namespace std::this_thread;     // sleep_for, sleep_until
using std::chrono::system_clock;
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

class globalMap
{
private:

    //// Размеры карт
    // Размер глобальной карты
    const int bigMapSize = 30;
    // Размер локальной карты
    const int localMapSize = 5;

    // Константы для обозначения ячеек внутри карты
    const int WALL = 55;
    const int HERO = -1;
    const int EXIT = -8;
    const int UNKNOWN = 99;
    const int VISIBLE = -9;
    // Обозначение ячейки, где мы уже были
    const int WAS_THERE = 40;

    // Координаты выхода
    const int exitCoordX = 20;
    const int exitCoordY = 20;

    // Глобальные координаты героя
    int heroCoordX;
    int heroCoordY;

    string prevPath;

    int n = 0;
    int prevHeroCoordX;
    int prevHeroCoordY;

    // Локальные координаты героя
    const int localHeroX = 2;
    const int localHeroY = 2;

    vector<int> pathX;
    vector<int> pathY;

    //// Карты
    // Глобальная
    int** map;
    // Локальная
    int** localMap;
    int** prevLocalMap;
    // Текущая раскрытая
    int** currentMap;

public:

    struct point{
        int x;
        int y;
    };

    void checkForOverloadingCells();

    globalMap();
    void connectGlobalAndLocalMap();
    void connectCurrentAndLocalMap();

    void findNextStep();


    void setGlobalMap();
    void isFindWALL();

    // Get-теры
    int getUNKNOWN() const;
    int getExitCoordY() const;
    int getExitCoordX() const;
    int getHeroCoordY() const;
    int getHeroCoordX() const;
    int getEXIT() const;
    int getHERO() const;
    int getWALL() const;
    int getVISIBLE() const;
    int getLocalMapSize() const;
    int getBigMapSize() const;
    int **getMap() const;
    int **getLocalMap() const;
    int **getCurrentMap() const;

    int getWasThere() const;
};

#endif // GLOBALMAP_H
