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

    const int bigMapSize = 30;
    const int localMapSize = 5;
    const int WALL = 55;
    const int HERO = -1;
    const int EXIT = -8;
    const int wasThere = 40;

    int heroCoordX;
    int heroCoordY;
    const int exitCoordX = 20;
    const int exitCoordY = 20;
    const int UNKNOWN = 99;

    const int localHeroX = 2;
    const int localHeroY = 2;

    int** map;
    int** localMap;
    int** currentMap;





public:

    struct point{
        int x;
        int y;
    };
    vector<point> resDirection;

    globalMap();
    void connectGlobalAndLocalMap();
    void connectCurrentAndLocalMap();

    void findNextStep();


    void setGlobalMap();
    void isFindWALL();

    int getUNKNOWN() const;
    int getExitCoordY() const;
    int getExitCoordX() const;
    int getHeroCoordY() const;
    int getHeroCoordX() const;
    int getEXIT() const;
    int getHERO() const;
    int getWALL() const;
    int getLocalMapSize() const;
    int getBigMapSize() const;
    int **getMap() const;
    int **getLocalMap() const;
    int **getCurrentMap() const;
    vector<point> getResDirection() const;
};

#endif // GLOBALMAP_H
