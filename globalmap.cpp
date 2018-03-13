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

vector<globalMap::point> globalMap::getResDirection() const
{
    return resDirection;
}

globalMap::globalMap()
{
    // Наша начальная позиция
    heroCoordX = 3;
    heroCoordY = 6;

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

    connectGlobalAndLocalMap();

    for(int i = 0; i < localMapSize; i++)
        for(int j = 0; j < localMapSize; j++)
            if(localMap[i][j] == WALL){
                //// В зависимости от того, где расположено препятствие
                /// рисовать невидимые участки
                // Сверху
                if((i == localHeroX)&&(j + 1 == localHeroY)){
                    cout << "Up" << endl;

                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                }
                // Снизу
                if((i == localHeroX)&&(j - 1 == localHeroY)){
                    cout << "Down" << endl;

                    if(localMap[i][j + 1] != WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }
                // Справа
                if((i - 1 == localHeroX)&&(j == localHeroY)){
                    cout << "Right" << endl;

                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                }
                //  Слева
                if((i + 1 == localHeroX)&&(j == localHeroY)){
                    cout << "Left" << endl;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j] != WALL)
                        localMap[i - 1][j] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }
                //  Верхняя правая диагональ
                if((i - 1 == localHeroX)&&(j + 1 == localHeroY)){
                    cout << "Up right" << endl;

                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                }
                // Нижняя правая диагональ
                if((i - 1 == localHeroX)&&(j - 1 == localHeroY)){
                    cout << "Down right" << endl;

                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i][j + 1]!= WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                }

                // Верхняя левая диагональ
                if((i + 1 == localHeroX)&&(j + 1 == localHeroY)){
                    cout << "Up left" << endl;

                    if(localMap[i - 1][j] != WALL)
                        localMap[i - 1][j] = UNKNOWN;
                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                }
                // Нижняя левая диагональ
                if((i + 1 == localHeroX)&&(j - 1 == localHeroY)){
                    cout << "Down left" << endl;

                    if(localMap[i - 1][j] != WALL)
                        localMap[i - 1][j] = UNKNOWN;
                    if(localMap[i][j + 1]!= WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }

            }
    connectCurrentAndLocalMap();

}
void globalMap::connectCurrentAndLocalMap(){
    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;
    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            currentMap[x][y++] = localMap[i][j];
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
    }
}

void globalMap::connectGlobalAndLocalMap(){
    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;

    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            localMap[i][j] = map[x][y++];
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
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
}

void globalMap::findNextStep(){


    point p;
    p.x = heroCoordX;
    p.y = heroCoordY;
    // Право
    if((map[heroCoordX + 1][heroCoordY] != WALL)&&(map[heroCoordX + 1][heroCoordY] != UNKNOWN)){
        cout << "GO RIGHT" << endl;

        currentMap[heroCoordX][heroCoordY] = wasThere;
        heroCoordX++;
        currentMap[heroCoordX][heroCoordY] = HERO;


    }
    // Низ
    else if((map[heroCoordX][heroCoordY - 1] != WALL)&&(map[heroCoordX][heroCoordY - 1] != UNKNOWN)){
        cout << "GO UP" << endl;

        currentMap[heroCoordX][heroCoordY] = wasThere;

        heroCoordY--;
        currentMap[heroCoordX][heroCoordY] = HERO;

    }

    // Верх
    else if((map[heroCoordX][heroCoordY + 1] != WALL)&&(map[heroCoordX][heroCoordY + 1] != UNKNOWN)){

        cout << "GO DOWN" << endl;
        currentMap[heroCoordX][heroCoordY] = wasThere;

        heroCoordY++;
        currentMap[heroCoordX][heroCoordY] = HERO;


    }

    // Лево
    else if((map[heroCoordX - 1][heroCoordY ] != WALL)&&(map[heroCoordX - 1][heroCoordY] != UNKNOWN)){
        cout << "GO LEFT" << endl;

        currentMap[heroCoordX][heroCoordY] = wasThere;

        heroCoordX--;
        currentMap[heroCoordX][heroCoordY] = HERO;

    }


}
