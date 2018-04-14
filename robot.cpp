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
    access = OM->isFreeGoUp();
    if(access == true){
        OM->goUp();
        NTR->goUp();
    }
}
void Robot::goDown(){
    access = OM->isFreeGoDown();
    if(access == true){
        OM->goDown();
        NTR->goDown();
    }
}

void Robot::goRight(){
    access = OM->isFreeGoRight();
    if(access == true){
        OM->goRight();
        NTR->goRight();
    }
}

void Robot::goLeft(){
    access = OM->isFreeGoLeft();
    if(access == true){
        OM->goLeft();
        NTR->goLeft();
    }
}

void Robot::connectOpenMap(){
    heroCoordX = NTR->getHeroCoordX();
    heroCoordY = NTR->getHeroCoordY();
    globalMapSize = NTR->getGlobalMapSize();

    OM = new OpenMap(globalMapSize, heroCoordX, heroCoordY);

}
