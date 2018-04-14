#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include"localmap.h"
#include"globalmap.h"


class Navigator
{
private:
    LocalMap* LM;

    int locMapSize;
    int globMapSize;

    int globHeroX;
    int globHeroY;

    int** globMap;
    int** locMap;
public:
    LocalMap* findRobotOnGlobalMap();
    Navigator(GlobalMap* GM);
    void setCoordinates(int x, int y);

    void goUp();
    void goDown();
    void goLeft();
    void goRight();

    int getHeroCoordX() const;
    int getHeroCoordY() const;
    int getGlobalMapSize() const;
};

#endif // NAVIGATOR_H
