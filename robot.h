#ifndef ROBOT_H
#define ROBOT_H
#include "navigator.h"
#include "openmap.h"
#include "globalmap.h"
#include "localmap.h"
#include <stdio.h>

#include <unistd.h>


class Robot
{
private:
    GlobalMap* GM;
    OpenMap* OM;
    LocalMap* LM;
    Navigator* NTR;
    int** localMap;

    int bigMapSize;
    int WALL;

    int heroCoordX;
    int heroCoordY;

    int UNKNOWN;
    int VISIBLE;
    int WAS_THERE;
    int** map;

    bool access;
public:
    Robot();

    void showSituation();
    void display();
    void getInitParams();

    void goUp();
    void goDown();
    void goLeft();
    void goRight();
};

#endif // ROBOT_H
