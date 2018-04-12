#include "openmap.h"

OpenMap::OpenMap(GlobalMap* glMap):Map(glMap->getSize())

{
    GM = new GlobalMap();
    LM = new LocalMap();

    GM = glMap;

    heroCoordX = glMap->getHeroCoordX();
    heroCoordY = glMap->getHeroCoordY();


    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j){
            map[i][j] = UNKNOWN;
        }
}


void OpenMap::connectOpenAndLocalMap(LocalMap* LM){
    LM->isFindWALL();
   if(n >= 1) checkForOverloadingCells(LM);
   n++;

    int localMapSize = LM->getSize();
    int** localMap = LM->getMap();

    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;
    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
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
            if((x >= size)||(y >= size)||(x < 0)||(y < 0))
                continue;

            if((map[x][y] == VISIBLE)&&(localMap[i][j] == UNKNOWN))
                localMap[i][j] = VISIBLE;
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

    pathX.push_back(heroCoordX);
    pathY.push_back(heroCoordY);

    //        cout << "GO RIGHT" << endl;
    heroCoordX++;
    for(uint i = 0; i < pathX.size(); i++){
        map[pathX[i]][pathY[i]] = WAS_THERE;
    }
}


bool OpenMap::isFreeGoLeft(){
    if((map[heroCoordX - 1][heroCoordY] != WALL)&&(map[heroCoordX - 1][heroCoordY] != UNKNOWN))
        return 1;
    else
        return 0;
}
void OpenMap::goLeft(){

    pathX.push_back(heroCoordX);
    pathY.push_back(heroCoordY);

    //        cout << "GO LEFT" << endl;
    heroCoordX--;
    for(uint i = 0; i < pathX.size(); i++){
        map[pathX[i]][pathY[i]] = WAS_THERE;
    }
}

bool OpenMap::isFreeGoUp(){
    // Верх
    if((map[heroCoordX][heroCoordY - 1] != WALL)&&(map[heroCoordX][heroCoordY - 1] != UNKNOWN))
        return 1;
    else
        return 0;
}

void OpenMap::goUp(){
    pathX.push_back(heroCoordX);
    pathY.push_back(heroCoordY);
    //        cout << "GO UP" << endl;
    heroCoordY--;
    for(uint i = 0; i < pathX.size(); i++){
        map[pathX[i]][pathY[i]] = WAS_THERE;
    }
}

bool OpenMap::isFreeGoDown(){
    // Низ
    if((map[heroCoordX][heroCoordY + 1] != WALL)&&(map[heroCoordX][heroCoordY + 1] != UNKNOWN))
        return 1;
    else
        return 0;
}
void OpenMap::goDown(){

    pathX.push_back(heroCoordX);
    pathY.push_back(heroCoordY);
    //        cout << "GO DOWN" << endl;
    heroCoordY++;
    for(uint i = 0; i < pathX.size(); i++){
        map[pathX[i]][pathY[i]] = WAS_THERE;
    }
}

