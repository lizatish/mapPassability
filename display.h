#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <GL/glut.h>
using namespace std;

class display
{
public:
    const int N = 30;
    const int WALL = -4;
    const int HERO = -1;
    const int EXIT = -8;
    const int heroCoordX = 3;
    const int heroCoordY = 6;
    const int notVisible = -2;
    int exitCoordX = 20;
    int exitCoordY = 20;
    display();
    void showGraphics();
};

#endif // DISPLAY_H
