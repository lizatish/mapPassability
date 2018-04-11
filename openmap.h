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
public:
    OpenMap(GlobalMap* glMap);


    void checkForOverloadingCells(LocalMap* LM);
    void connectOpenAndLocalMap(LocalMap* LM);

        void goRight();
        void goLeft();
        void goDown();
        void goUp();
    };


#endif // OPENMAP_H
