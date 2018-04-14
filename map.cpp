#include "map.h"

Map::Map(int initSize)
{
    size = initSize;
    map = new int* [initSize];
    for(int i = 0; i < initSize; i++){
        map[i] = new int[initSize];
    }
}

int Map::getUNKNOWN() const { return UNKNOWN; }
int Map::getWALL() const { return WALL; }
int Map::getSize() const { return size; }
int **Map::getMap() const { return map; }
int Map::getVISIBLE() const { return VISIBLE; }
int Map::getWasThere() const { return WAS_THERE; }
