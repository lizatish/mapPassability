#ifndef LOCALMAP_H
#define LOCALMAP_H

#include "map.h"
#include "globalmap.h"


class LocalMap : public Map
{
private:
    int globalMapSize = 30;
public:
    LocalMap();



    void isFindWALL();


};

#endif // LOCALMAP_H
