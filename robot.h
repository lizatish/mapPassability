#ifndef ROBOT_H
#define ROBOT_H
#include "navigator.h"
#include "openmap.h"
#include "globalmap.h"
#include "localmap.h"
#include "display.h"

#include <stdio.h>

#include <unistd.h>


class Robot
{
private:
    OpenMap* OM;
    Navigator* NTR;

    int globalMapSize;
    int WALL;

    int heroCoordX;
    int heroCoordY;

    int UNKNOWN;
    int VISIBLE;
    int WAS_THERE;
    int** map;

    bool access;
public:
    Robot(Navigator* initNav);

    OpenMap* showSituation();
    void connectOpenMap();

    void goUp();
    void goDown();
    void goLeft();
    void goRight();
};

#endif // ROBOT_H
