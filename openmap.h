#ifndef OPENMAP_H
#define OPENMAP_H

#include "map.h"
#include "globalmap.h"
#include "localmap.h"


class OpenMap : public Map
{
private:
    GlobalMap* GM;
    LocalMap* LM;

    vector <int> pathX;
    vector <int> pathY;
int n = 0;
public:
    OpenMap(GlobalMap* glMap);

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


};


#endif // OPENMAP_H
