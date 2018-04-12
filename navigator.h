#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include"localmap.h"
#include"globalmap.h"


class Navigator
{
private:
    int locMapSize;
    int globMapSize;

    int globHeroX;
    int globHeroY;

    int** globMap;
public:
    Navigator(GlobalMap* GM, LocalMap* LM);
    int** connectGlobalAndLocalMap( int** locMap);
    void setCoordinates(int x, int y);

    void goUp();
    void goDown();
    void goLeft();
    void goRight();

};

#endif // NAVIGATOR_H
