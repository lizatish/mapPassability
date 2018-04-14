#ifndef OPENMAP_H
#define OPENMAP_H

#include "map.h"
#include "globalmap.h"
#include "localmap.h"


class OpenMap : public Map
{
private:
    LocalMap* LM;

    vector <int> pathX;
    vector <int> pathY;
    int n = 0;

    int heroCoordX;
    int heroCoordY;
public:
    OpenMap(int initSize, int heroX, int heroY);

    bool isFreeGoRight();
    bool isFreeGoLeft();
    bool isFreeGoUp();
    bool isFreeGoDown();

    void goUp();
    void goDown();
    void goLeft();
    void goRight();

    void checkForOverloadingCells(LocalMap* LM);
    void connectOpenAndLocalMap(LocalMap* LM);

    void setHeroCoords(int x, int y);

    int getHeroCoordX() const;
    int getHeroCoordY() const;
};


#endif // OPENMAP_H
