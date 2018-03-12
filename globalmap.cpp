#include "globalmap.h"

int globalMap::getUNKNOWN() const
{
    return UNKNOWN;
}

int globalMap::getExitCoordY() const
{
    return exitCoordY;
}

int globalMap::getExitCoordX() const
{
    return exitCoordX;
}

int globalMap::getHeroCoordY() const
{
    return heroCoordY;
}

int globalMap::getHeroCoordX() const
{
    return heroCoordX;
}

int globalMap::getEXIT() const
{
    return EXIT;
}

int globalMap::getHERO() const
{
    return HERO;
}

int globalMap::getWALL() const
{
    return WALL;
}

int globalMap::getLocalMapSize() const
{
    return localMapSize;
}

int globalMap::getBigMapSize() const
{
    return bigMapSize;
}

int **globalMap::getMap() const
{
    return map;
}


int **globalMap::getLocalMap() const
{
    return localMap;
}


int **globalMap::getCurrentMap() const
{
    return currentMap;
}

globalMap::globalMap()
{


    map = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        map[i] = new int[bigMapSize];
    }
    localMap = new int* [localMapSize];
    for(int i = 0; i < localMapSize; i++){
        localMap[i] = new int[localMapSize];
    }

    currentMap = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        currentMap[i] = new int[bigMapSize];
    }
}



void globalMap::isFindWALL(){

    for(int i = 0; i < localMapSize; i++)
        for(int j = 0; j < localMapSize; j++)
            if(localMap[i][j] == WALL){
                //// В зависимости от того, где расположено препятствие
                /// рисовать невидимые участки
                // Сверху
                if((i == heroCoordX)||(j - 1 == heroCoordY)){
                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                }
                // Снизу
                if((i == heroCoordX)||(j + 1 == heroCoordY)){
                    if(localMap[i][j + 1] != WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }
                // Справа
                if((i - 1 == heroCoordX)||(j == heroCoordY)){
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                }
                // Слева
                if((i + 1 == heroCoordX)||(j == heroCoordY)){
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j] != WALL)
                        localMap[i - 1][j] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }
                // Верхняя правая диагональ
                if((i - 1 == heroCoordX)||(j + 1 == heroCoordY)){
                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                }
                // Нижняя правая диагональ
                if((i - 1 == heroCoordX)||(j - 1 == heroCoordY)){
                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i][j + 1]!= WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                }

                // Верхняя левая диагональ
                if((i + 1 == heroCoordX)||(j + 1 == heroCoordY)){
                    if(localMap[i - 1][j] != WALL)
                        localMap[i - 1][j] = UNKNOWN;
                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                }
                // Нижняя левая диагональ
                if((i - 1 == heroCoordX)||(j - 1 == heroCoordY)){
                    if(localMap[i - 1][j] != WALL)
                        localMap[i - 1][j] = UNKNOWN;
                    if(localMap[i][j + 1]!= WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }

            }

    int x = heroCoordX;
    int y = heroCoordY;

    for(int i = x - 2; i < x + localMapSize; i++)
        for(int j = y - 2; j < y + localMapSize; j++){
            currentMap[i][j] = map[i][j];
        }

}

void globalMap::connectGlobalAndLocalMap(){
    int x = heroCoordX - 3;
    int y = heroCoordY - 3;

    for(int i = x; i < x + localMapSize; i++)
        for(int j = y; j < y + localMapSize; j++){
            localMap[i][j] = map[i][j];
        }

}

void globalMap::setGlobalMap(){

    srand(time(NULL));
    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
        {
            if (rand() % 4 == 0)
                map[i][j] = WALL;
            else
                map[i][j] = 0;
        }
    for (int i = 0; i < bigMapSize; ++i)
    {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][bigMapSize - 1] = WALL;
        map[bigMapSize - 1][i] = WALL;
    }
    map[heroCoordX][heroCoordY] = HERO;
    map[exitCoordX][exitCoordY] = EXIT;

    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j){
            currentMap[i][j] = UNKNOWN;
        }
    connectGlobalAndLocalMap();
}
