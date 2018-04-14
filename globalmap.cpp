#include "globalmap.h"

GlobalMap::GlobalMap():Map(30){
}
GlobalMap::GlobalMap(int glSize):Map(glSize){
}


void GlobalMap::setGlobalMap(){

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
void GlobalMap::setGlobalMap(int** glMap){
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            map[i][j] = glMap[i][j];
}
