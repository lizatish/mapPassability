#include "map.h"

int Map::getUNKNOWN() const
{
    return UNKNOWN;
}

int Map::getHeroCoordY() const
{
    return heroCoordY;
}

int Map::getHeroCoordX() const
{
    return heroCoordX;
}

int Map::getHERO() const
{
    return HERO;
}

int Map::getWALL() const
{
    return WALL;
}

int Map::getLocalMapSize() const
{
    return localMapSize;
}

int Map::getBigMapSize() const
{
    return bigMapSize;
}

int **Map::getMap() const
{
    return map;
}


int **Map::getLocalMap() const
{
    return localMap;
}


int **Map::getCurrentMap() const
{
    return currentMap;
}

int Map::getVISIBLE() const
{
    return VISIBLE;
}
int Map::getWasThere() const
{
    return WAS_THERE;
}


Map::Map(int glMapSize, int locMapSize){
    bigMapSize = glMapSize;
    localMapSize = locMapSize;

    // Наша начальная позиция
    heroCoordX = glMapSize / 2 - 1;
    heroCoordY =  glMapSize / 2 - 1;
    prevHeroCoordX = heroCoordX;
    prevHeroCoordY = heroCoordY;

    map = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        map[i] = new int[bigMapSize];
    }
    localMap = new int* [localMapSize];
    for(int i = 0; i < localMapSize; i++){
        localMap[i] = new int[localMapSize];
    }
    prevLocalMap = new int* [localMapSize];
    for(int i = 0; i < localMapSize; i++){
        prevLocalMap[i] = new int[localMapSize];
    }

    currentMap = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        currentMap[i] = new int[bigMapSize];
    }

    prevPath = "";
}

Map::Map()
{
    // Размеры по умолчанию
    bigMapSize = 30;
    localMapSize = 5;
    // Наша начальная позиция
    heroCoordX = 10;
    heroCoordY = 10;
    prevHeroCoordX = heroCoordX;
    prevHeroCoordY = heroCoordY;

    map = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        map[i] = new int[bigMapSize];
    }
    localMap = new int* [localMapSize];
    for(int i = 0; i < localMapSize; i++){
        localMap[i] = new int[localMapSize];
    }
    prevLocalMap = new int* [localMapSize];
    for(int i = 0; i < localMapSize; i++){
        prevLocalMap[i] = new int[localMapSize];
    }

    currentMap = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        currentMap[i] = new int[bigMapSize];
    }

    prevPath = "";
}




void Map::isFindWALL(){
    connectGlobalAndLocalMap();

    for(int i = 0; i < localMapSize; i++)
        for(int j = 0; j < localMapSize; j++)
            if(localMap[i][j] == WALL){
                //// В зависимости от того, где расположено препятствие
                /// рисовать невидимые участки
                // Сверху
                if((i == localHeroX)&&(j + 1 == localHeroY)){
                    // cout << "Up" << endl;

                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                }
                // Снизу
                if((i == localHeroX)&&(j - 1 == localHeroY)){
                    // cout << "Down" << endl;

                    if(localMap[i][j + 1] != WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }
                // Справа
                if((i - 1 == localHeroX)&&(j == localHeroY)){
                    // cout << "Right" << endl;

                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                }
                //  Слева
                if((i + 1 == localHeroX)&&(j == localHeroY)){
                    //  cout << "Left" << endl;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j] != WALL)
                        localMap[i - 1][j] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }
                //  Верхняя правая диагональ
                if((i - 1 == localHeroX)&&(j + 1 == localHeroY)){
                    //  cout << "Up right" << endl;

                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                }
                // Нижняя правая диагональ
                if((i - 1 == localHeroX)&&(j - 1 == localHeroY)){
                    //  cout << "Down right" << endl;

                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i][j + 1]!= WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                }

                // Верхняя левая диагональ
                if((i + 1 == localHeroX)&&(j + 1 == localHeroY)){
                    //  cout << "Up left" << endl;

                    if((localMap[i - 1][j] != WALL))
                        localMap[i - 1][j] = UNKNOWN;
                    if((localMap[i][j - 1] != WALL))
                        localMap[i][j - 1] = UNKNOWN;
                    if((localMap[i - 1][j - 1] != WALL))
                        localMap[i - 1][j - 1] = UNKNOWN;
                }
                // Нижняя левая диагональ
                if((i + 1 == localHeroX)&&(j - 1 == localHeroY)){
                    //   cout << "Down left" << endl;
                    if((localMap[i - 1][j] != WALL))
                        localMap[i - 1][j] = UNKNOWN;
                    if((localMap[i][j + 1]!= WALL))
                        localMap[i][j + 1] = UNKNOWN;
                    if((localMap[i - 1][j + 1] != WALL))
                        localMap[i - 1][j + 1] = UNKNOWN;
                }

            }
    if(n >= 1){
        // Проверка на пересекаемые зоны предыдущей версии карты и только что открытой
        checkForOverloadingCells();
    }
    n++;

    // Нарисовать на текущей открытой карте то, что только что увидели
    connectCurrentAndLocalMap();

}
void Map::connectCurrentAndLocalMap(){
    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;
    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            if((x >= bigMapSize)||(y >= bigMapSize)||(x < 0)||(y < 0))
                continue;
            currentMap[x][y++] = localMap[i][j];
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
    }
}

void Map::connectGlobalAndLocalMap(){
    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;

    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            if((x >= bigMapSize)||(y >= bigMapSize)||(x < 0)||(y < 0))
                continue;
            localMap[i][j] = map[x][y++];
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
    }
}

void Map::setGlobalMap( int** initMap){

    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
            map[i][j] = initMap[i][j];

    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j){
            currentMap[i][j] = UNKNOWN;
        }
    isFindWALL();

}
void Map::setGlobalMap(){

    srand(time(NULL));
    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
        {
            if (rand() % 4 == 0)
                map[i][j] = WALL;
            else
                map[i][j] = VISIBLE;
        }
    for (int i = 0; i < bigMapSize; ++i)
    {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][bigMapSize - 1] = WALL;
        map[bigMapSize - 1][i] = WALL;
    }
    map[heroCoordX][heroCoordY] = HERO;

    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j){
            currentMap[i][j] = UNKNOWN;
        }

    isFindWALL();
}

void Map::findNextStep(){

    prevHeroCoordX = heroCoordX;
    prevHeroCoordY = heroCoordY;

    pathX.push_back(heroCoordX);
    pathY.push_back(heroCoordY);


    // Низ
    if((map[heroCoordX][heroCoordY + 1] != WALL)&&(map[heroCoordX][heroCoordY + 1] != UNKNOWN)){
        cout << "GO DOWN" << endl;
        prevPath = "Down";
        heroCoordY++;
    }

    // Право
    else if((map[heroCoordX + 1][heroCoordY] != WALL)&&(map[heroCoordX + 1][heroCoordY] != UNKNOWN)){
        cout << "GO RIGHT" << endl;
        prevPath = "Right";
        heroCoordX++;
    }

    // Верх
    else if((map[heroCoordX][heroCoordY - 1] != WALL)&&(map[heroCoordX][heroCoordY - 1] != UNKNOWN)){
        cout << "GO UP" << endl;
        prevPath = "Up";
        heroCoordY--;

    }

    // Лево
    else if((map[heroCoordX - 1][heroCoordY] != WALL)&&(map[heroCoordX - 1][heroCoordY] != UNKNOWN)){
        cout << "GO LEFT" << endl;
        prevPath = "Left";
        heroCoordX--;

    }
    currentMap[heroCoordX][heroCoordY] = HERO;




    for(uint i = 0; i < pathX.size(); i++){
        map[pathX[i]][pathY[i]] = WAS_THERE;
    }


}

void Map::setHeroCoordXY(int x, int y)
{
    heroCoordX = x;
    heroCoordY = y;
    prevHeroCoordX = heroCoordX;
    prevHeroCoordY = heroCoordY;

}

void Map::checkForOverloadingCells(){


    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;

    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            if((x >= bigMapSize)||(y >= bigMapSize)||(x < 0)||(y < 0))
                continue;

            if((currentMap[x][y] == VISIBLE)&&(localMap[i][j] == UNKNOWN))
                localMap[i][j] = VISIBLE;
            else if(currentMap[x][y] == WAS_THERE)
                localMap[i][j] = WAS_THERE;
            y++;
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
    }

}


void Map::goLeft(){


    if((map[heroCoordX - 1][heroCoordY] != WALL)&&(map[heroCoordX - 1][heroCoordY] != UNKNOWN)){
        prevHeroCoordX = heroCoordX;
        prevHeroCoordY = heroCoordY;

        pathX.push_back(heroCoordX);
        pathY.push_back(heroCoordY);

        //        cout << "GO LEFT" << endl;
        prevPath = "Left";
        heroCoordX--;
        currentMap[heroCoordX][heroCoordY] = HERO;
        for(uint i = 0; i < pathX.size(); i++){
            currentMap[pathX[i]][pathY[i]] = WAS_THERE;
        }
    }
    isFindWALL();
}

void  Map::goRight(){


    if((map[heroCoordX + 1][heroCoordY] != WALL)&&(map[heroCoordX + 1][heroCoordY] != UNKNOWN)){

        prevHeroCoordX = heroCoordX;
        prevHeroCoordY = heroCoordY;

        pathX.push_back(heroCoordX);
        pathY.push_back(heroCoordY);

        //        cout << "GO RIGHT" << endl;
        prevPath = "Right";
        heroCoordX++;
        currentMap[heroCoordX][heroCoordY] = HERO;
        for(uint i = 0; i < pathX.size(); i++){
            currentMap[pathX[i]][pathY[i]] = WAS_THERE;
        }
    }
    isFindWALL();

}

void  Map::goDown(){

    // Низ
    if((map[heroCoordX][heroCoordY + 1] != WALL)&&(map[heroCoordX][heroCoordY + 1] != UNKNOWN)){

        prevHeroCoordX = heroCoordX;
        prevHeroCoordY = heroCoordY;

        pathX.push_back(heroCoordX);
        pathY.push_back(heroCoordY);
        //        cout << "GO DOWN" << endl;
        prevPath = "Down";
        heroCoordY++;
        currentMap[heroCoordX][heroCoordY] = HERO;
        for(uint i = 0; i < pathX.size(); i++){
            currentMap[pathX[i]][pathY[i]] = WAS_THERE;
        }
    }
    isFindWALL();

}

void  Map::goUp(){


    // Верх
    if((map[heroCoordX][heroCoordY - 1] != WALL)&&(map[heroCoordX][heroCoordY - 1] != UNKNOWN)){

        prevHeroCoordX = heroCoordX;
        prevHeroCoordY = heroCoordY;

        pathX.push_back(heroCoordX);
        pathY.push_back(heroCoordY);
        //        cout << "GO UP" << endl;
        prevPath = "Up";
        heroCoordY--;
        currentMap[heroCoordX][heroCoordY] = HERO;
        for(uint i = 0; i < pathX.size(); i++){
            currentMap[pathX[i]][pathY[i]] = WAS_THERE;
        }

    }
    isFindWALL();

}
