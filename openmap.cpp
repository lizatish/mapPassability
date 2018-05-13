#include "openmap.h"

int OpenMap::getHeroCoordX() const
{
    return heroCoordX;
}

int OpenMap::getHeroCoordY() const
{
    return heroCoordY;
}
int OpenMap::getExitCoordX() const
{
    return exitCoordX;
}

int OpenMap::getExitCoordY() const
{
    return exitCoordY;
}

vector<pair<int, int> > OpenMap::getPath() const
{
    return path;
}

int OpenMap::getEXIT() const
{
    return EXIT;
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
OpenMap::OpenMap(int initSize, int heroX, int heroY, int exX, int exY):Map(initSize)

{
    LM = new LocalMap();

    heroCoordX = heroX;
    heroCoordY = heroY;
    exitCoordX = exX;
    exitCoordY = exY;


    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j){
            map[i][j] = UNKNOWN;
        }
    map[exitCoordX][exitCoordY] = EXIT;

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
            else if(map[x][y] == EXIT)
                    localMap[i][j] = EXIT;
            else if((map[x][y] == VISIBLE)&&(localMap[i][j] == UNKNOWN))
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



bool  OpenMap::isFreeGoDiaUL(){
    if((map[heroCoordX - 1][heroCoordY - 1] != WALL)&&(map[heroCoordX - 1][heroCoordY - 1] != UNKNOWN))
        return 1;
    else
        return 0;
}

bool OpenMap::isFreeGoDiaUR(){
    if((map[heroCoordX + 1][heroCoordY - 1] != WALL)&&(map[heroCoordX + 1][heroCoordY - 1] != UNKNOWN))
        return 1;
    else
        return 0;
}

bool OpenMap::isFreeGoDiaDR(){
    if((map[heroCoordX + 1][heroCoordY + 1] != WALL)&&(map[heroCoordX + 1][heroCoordY + 1] != UNKNOWN))
        return 1;
    else
        return 0;
}

bool OpenMap::isFreeGoDiaDL(){
    if((map[heroCoordX - 1][heroCoordY + 1] != WALL)&&(map[heroCoordX - 1][heroCoordY + 1] != UNKNOWN))
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

void OpenMap::goDiaUR(){
    path.push_back(make_pair(heroCoordX, heroCoordY));

    heroCoordY--; heroCoordX++;
    for(uint i = 0; i < path.size(); i++)
        map[path[i].first][path[i].second] = WAS_THERE;
}
void OpenMap::goDiaUL(){
    path.push_back(make_pair(heroCoordX, heroCoordY));

    heroCoordY--; heroCoordX--;
    for(uint i = 0; i < path.size(); i++)
        map[path[i].first][path[i].second] = WAS_THERE;
}
void OpenMap::goDiaDR(){
    path.push_back(make_pair(heroCoordX, heroCoordY));

    heroCoordY++; heroCoordX++;
    for(uint i = 0; i < path.size(); i++)
        map[path[i].first][path[i].second] = WAS_THERE;
}
void OpenMap::goDiaDL(){
    path.push_back(make_pair(heroCoordX, heroCoordY));

    heroCoordY++; heroCoordX--;
    for(uint i = 0; i < path.size(); i++)
        map[path[i].first][path[i].second] = WAS_THERE;
}
