#include "navigator.h"

Navigator::Navigator(GlobalMap* GM)
{
    globMapSize = GM->getSize();

    globHeroX = globMapSize / 2 - 1;
    globHeroY = globMapSize / 2 - 1;


    globMap = new int* [globMapSize];
    for(int i = 0; i < globMapSize; i++){
        globMap[i] = new int[globMapSize];
    }

    globMap = GM->getMap();
    LM = new LocalMap();
}

int Navigator::getHeroCoordX() const
{
    return globHeroX;
}

int Navigator::getHeroCoordY() const
{
    return globHeroY;
}

int Navigator::getGlobalMapSize() const
{
    return globMapSize;
}

LocalMap* Navigator::findRobotOnGlobalMap(){
    locMapSize =  LM->getSize();
    locMap = LM->getMap();

    int x = globHeroX - (locMapSize - 1) / 2;
    int y = globHeroY - (locMapSize - 1) / 2;



    for(int i = 0; i < locMapSize; i++){
        int j = 0;
        while(y < 0){
            y++;
            j++;
        }
        for(j; j < locMapSize; j++){
            if((x >= globMapSize)||(y >= globMapSize)||(x < 0)||(y < 0))
                continue;
            locMap[i][j] = globMap[x][y++];
        }
        x++;
        y = globHeroY - (locMapSize - 1) / 2;
    }
    return LM;
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
