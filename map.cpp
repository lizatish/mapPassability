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

void Map::setMap(){

    srand(time(NULL));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            if (rand() % 4 == 0)
                map[i][j] = WALL;
            else
                map[i][j] = VISIBLE;
        }
    for (int i = 0; i < size; ++i)
    {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][size - 1] = WALL;
        map[size - 1][i] = WALL;
    }
}
