#include "robot.h"

Robot::Robot(Navigator* initNav)
{
    NTR = initNav;
    connectOpenMap();
}

OpenMap* Robot::showSituation(){

    LocalMap* LM = NTR->findRobotOnGlobalMap();
    OM->connectOpenAndLocalMap(LM);
    return OM;
}

void Robot::goUp(){
    isFreeNeedCell = OM->isFreeGoUp();
    if(isFreeNeedCell == true){
        OM->goUp();
        NTR->goUp();
    }
}
void Robot::goDown(){
    isFreeNeedCell = OM->isFreeGoDown();
    if(isFreeNeedCell == true){
        OM->goDown();
        NTR->goDown();
    }
}

void Robot::goRight(){
    isFreeNeedCell = OM->isFreeGoRight();
    if(isFreeNeedCell == true){
        OM->goRight();
        NTR->goRight();
    }
}

void Robot::goLeft(){
    isFreeNeedCell = OM->isFreeGoLeft();
    if(isFreeNeedCell == true){
        OM->goLeft();
        NTR->goLeft();
    }
}

void Robot::connectOpenMap(){
    int heroCoordX = NTR->getHeroCoordX();
    int heroCoordY = NTR->getHeroCoordY();
    int globalMapSize = NTR->getGlobalMapSize();

    OM = new OpenMap(globalMapSize, heroCoordX, heroCoordY);

}
