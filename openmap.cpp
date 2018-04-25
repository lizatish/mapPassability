#include "openmap.h"

int OpenMap::getHeroCoordX() const
{
    return heroCoordX;
}

int OpenMap::getHeroCoordY() const
{
    return heroCoordY;
}

vector<pair<int, int> > OpenMap::getPath() const
{
    return path;
}

OpenMap::OpenMap(int initSize, int heroX, int heroY):Map(initSize)

{
    LM = new LocalMap();

    heroCoordX = heroX;
    heroCoordY = heroY;

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j){
            map[i][j] = UNKNOWN;
        }
}

void OpenMap::connectOpenAndLocalMap(LocalMap* LM){

    checkForOverloadingCells(LM);

    int localMapSize = LM->getSize();
    int** localMap = LM->getMap();

    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;
    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            while(y < 0){
                y++;
                j++;
            }
            if((x >= size)||(y >= size)||(x < 0)||(y < 0))
                continue;
            map[x][y++] = localMap[i][j];
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
    }
}

void OpenMap::checkForOverloadingCells(LocalMap* LM){

    int localMapSize = LM->getSize();
    int** localMap = LM->getMap();

    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;

    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            while(y < 0){
                y++;
                j++;
            }
            if((x >= size)||(y >= size)||(x < 0)||(y < 0))
                continue;

            if((map[x][y] == VISIBLE)&&(localMap[i][j] == UNKNOWN))
                localMap[i][j] = VISIBLE;
            else if((map[x][y] == WALL)&&(localMap[i][j] == UNKNOWN))
                localMap[i][j] = WALL;
            else if(map[x][y] == WAS_THERE)
                localMap[i][j] = WAS_THERE;
            y++;
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
    }

}

bool OpenMap::isFreeGoRight(){
    if((map[heroCoordX + 1][heroCoordY] != WALL)&&(map[heroCoordX + 1][heroCoordY] != UNKNOWN))
        return 1;
    else
        return 0;
}
void  OpenMap::goRight(){

    path.push_back(make_pair(heroCoordX, heroCoordY));

    heroCoordX++;
    for(uint i = 0; i < path.size(); i++)
        map[path[i].first][path[i].second] = WAS_THERE;
}


bool OpenMap::isFreeGoLeft(){
    if((map[heroCoordX - 1][heroCoordY] != WALL)&&(map[heroCoordX - 1][heroCoordY] != UNKNOWN))
        return 1;
    else
        return 0;
}
void OpenMap::goLeft(){

    path.push_back(make_pair(heroCoordX, heroCoordY));
    heroCoordX--;

    for(uint i = 0; i < path.size(); i++)
        map[path[i].first][path[i].second] = WAS_THERE;

}

bool OpenMap::isFreeGoUp(){
    // Верх
    if((map[heroCoordX][heroCoordY - 1] != WALL)&&(map[heroCoordX][heroCoordY - 1] != UNKNOWN))
        return 1;
    else
        return 0;
}

void OpenMap::goUp(){

    path.push_back(make_pair(heroCoordX, heroCoordY));

    heroCoordY--;
    for(uint i = 0; i < path.size(); i++)
        map[path[i].first][path[i].second] = WAS_THERE;
}

bool OpenMap::isFreeGoDown(){
    // Низ
    if((map[heroCoordX][heroCoordY + 1] != WALL)&&(map[heroCoordX][heroCoordY + 1] != UNKNOWN))
        return 1;
    else
        return 0;
}
void OpenMap::goDown(){

    path.push_back(make_pair(heroCoordX, heroCoordY));

    heroCoordY++;
    for(uint i = 0; i < path.size(); i++)
        map[path[i].first][path[i].second] = WAS_THERE;
}
