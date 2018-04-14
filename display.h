#ifndef DISPLAY_H
#define DISPLAY_H

#include <openmap.h>

class Display
{
private:
    int bigMapSize;
    int WALL;

    int heroCoordX;
    int heroCoordY;

    int** map;
public:
    Display();
    void display(OpenMap* OM);

};

#endif // DISPLAY_H
