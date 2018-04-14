#ifndef LOCALMAP_H
#define LOCALMAP_H

#include "map.h"
#include "globalmap.h"


class LocalMap : public Map
{
private:
    int heroCoordX;
    int heroCoordY;
public:
    LocalMap();

    void isFindWALL();
};

#endif // LOCALMAP_H
