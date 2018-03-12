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
    const int localMapSize = 3;
    const int WALL = 55;
    const int HERO = -1;
    const int EXIT = -8;
    const int heroCoordX = 3;
    const int heroCoordY = 6;
    const int exitCoordX = 20;
    const int exitCoordY = 20;
    const int UNKNOWN = 99;

    int** map;
    int** localMap;
    int** currentMap;


//    vector<pair<int, int> > resDirection;


public:
    globalMap();
    void connectGlobalAndLocalMap();


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
};

#endif // GLOBALMAP_H
