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
    bool isFreeNeedCell = OM->isFreeGoUp();
    if(isFreeNeedCell == true){
        OM->goUp();
        NTR->goUp();
    }
}
void Robot::goDown(){
    bool isFreeNeedCell = OM->isFreeGoDown();
    if(isFreeNeedCell == true){
        OM->goDown();
        NTR->goDown();
    }
}

void Robot::goRight(){
    bool isFreeNeedCell = OM->isFreeGoRight();
    if(isFreeNeedCell == true){
        OM->goRight();
        NTR->goRight();
    }
}

void Robot::goLeft(){
    bool isFreeNeedCell = OM->isFreeGoLeft();
    if(isFreeNeedCell == true){
        OM->goLeft();
        NTR->goLeft();
    }
}
void Robot::goDiaUR(){
    bool isFreeNeedCell = OM->isFreeGoDiaUR();
    if(isFreeNeedCell == true){
        OM->goDiaUR();
        NTR->goDiaUR();
    }
}
void Robot::goDiaUL(){
    bool isFreeNeedCell = OM->isFreeGoDiaUL();
    if(isFreeNeedCell == true){
        OM->goDiaUL();
        NTR->goDiaUL();
    }
}
void Robot::goDiaDR(){
    bool isFreeNeedCell = OM->isFreeGoDiaDR();
    if(isFreeNeedCell == true){
        OM->goDiaDR();
        NTR->goDiaDR();
    }
}
void Robot::goDiaDL(){
    bool isFreeNeedCell = OM->isFreeGoDiaDL();
    if(isFreeNeedCell == true){
        OM->goDiaDL();
        NTR->goDiaDL();
    }
}



void Robot::connectOpenMap(){
    int heroCoordX = NTR->getHeroCoordX();
    int heroCoordY = NTR->getHeroCoordY();

    int exitCoordX = NTR->getExitCoordX();
    int exitCoordY = NTR->getExitCoordY();

    int globalMapSize = NTR->getGlobalMapSize();

//    OM = new OpenMap(globalMapSize, heroCoordX, heroCoordY);
    OM = new OpenMap(globalMapSize, heroCoordX, heroCoordY, exitCoordX, exitCoordY);


}
