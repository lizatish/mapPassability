#ifndef GLOBALMAP_H
#define GLOBALMAP_H

#include "map.h"

class GlobalMap : public Map
{
public:
    GlobalMap();
    GlobalMap(int glSize);

    void setGlobalMap();
    void setGlobalMap(int** glMap);

};

#endif // GLOBALMAP_H
