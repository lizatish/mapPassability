#include "navigator.h"

Navigator::Navigator(GlobalMap* GM, LocalMap* LM)
{
    locMapSize =  LM->getSize();
    globMapSize = GM->getSize();

    globHeroX = GM->getHeroCoordX();
    globHeroY = GM->getHeroCoordY();


    globMap = new int* [globMapSize];
    for(int i = 0; i < globMapSize; i++){
        globMap[i] = new int[globMapSize];
    }

    globMap = GM->getMap();
}
int** Navigator::connectGlobalAndLocalMap( int** locMap){
    int x = globHeroX - (locMapSize - 1) / 2;
    int y = globHeroY - (locMapSize - 1) / 2;

    for(int i = 0; i < locMapSize; i++){
        for(int j = 0; j < locMapSize; j++){
            if((x >= globMapSize)||(y >= globMapSize)||(x < 0)||(y < 0))
                continue;
            locMap[i][j] = globMap[x][y++];
        }
        x++;
        y = globHeroY - (locMapSize - 1) / 2;
    }

    return locMap;
}

void Navigator::setCoordinates(int x, int y){
    globHeroX = x;
    globHeroY = y;
}

void Navigator::goUp(){
    globHeroY--;
}

void Navigator::goDown(){
    globHeroY++;

}

void Navigator::goLeft(){
    globHeroX--;

}

void Navigator::goRight(){
    globHeroX++;

}
