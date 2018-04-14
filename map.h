#ifndef MAP_H
#define MAP_H

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

class Map
{
protected:
    int** map;
    // Размер карты
    int size;

    // Константы для обозначения ячеек внутри карты
    const int WALL = 55;
    const int UNKNOWN = 99;
    const int VISIBLE = -9;
    const int WAS_THERE = 40;

public:
    Map(int initSize);
    Map();
    struct point{
        int x;
        int y;
    };

    void setMap( int** initMap);
    void setMap();

    // Get-теры
    int getUNKNOWN() const;
    int getEXIT() const;
    int getWALL() const;
    int getVISIBLE() const;
    int getSize() const;
    int **getMap() const;
    int getWasThere() const;
};

#endif // MAP_H

