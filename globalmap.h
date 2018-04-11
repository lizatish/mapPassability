#ifndef GLOBALMAP_H
#define GLOBALMAP_H

#include "map.h"

class GlobalMap : public Map
{
public:
    GlobalMap();
    GlobalMap(int glSize, int hCoordX, int hCoordY);

    void setGlobalMap();

};

#endif // GLOBALMAP_H
