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

    int locHeroX;
    int locHeroY;

    int** globMap;
public:
    Navigator(GlobalMap* GM, LocalMap* LM);
    int** connectGlobalAndLocalMap( int** locMap);

};

#endif // NAVIGATOR_H
