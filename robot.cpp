#include "robot.h"

Robot::Robot()
{
    getInitParams();
    int argc = 0;
    char* argv[1];
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(20, 1050 - 480 - 20);
    glutCreateWindow("Sample Algorithm");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, 480, 480, 0, -1, 1);
}

void Robot::getInitParams(){
    GM = new GlobalMap(20, 10, 10);
    GM->setGlobalMap();

    bigMapSize = GM->getSize();
    WALL = GM->getWALL();
    heroCoordX = GM->getHeroCoordX();
    heroCoordY = GM->getHeroCoordY();

    UNKNOWN = GM->getUNKNOWN();
    VISIBLE = GM->getVISIBLE();
    WAS_THERE = GM->getWasThere();

    map = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        map[i] = new int[bigMapSize];
    }

    LM = new LocalMap();
    localMap = LM->getMap();

    NTR = new Navigator(GM, LM);
    OM = new OpenMap(GM);

}


void Robot::showSituation(){

    localMap = NTR->connectGlobalAndLocalMap(localMap);
    OM->connectOpenAndLocalMap(LM);
    map = OM->getMap();

    display();

}

void Robot::display(){

    heroCoordX = OM->getHeroCoordX();
    heroCoordY = OM->getHeroCoordY();

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
        {
            if ((i == heroCoordX)&&(j == heroCoordY))
                glColor3f(0, 0, 1);
            else if (map[i][j] == WAS_THERE)
                glColor3f( 1, 0, 0);
            else if (map[i][j] == WALL)
                glColor3f(0, 0, 0);
            else if (map[i][j] == VISIBLE)
                glColor3f(1, 1, 1);
            else if (map[i][j] == UNKNOWN)
                glColor3f( 0.64,  0.64, 0.64);


            glVertex2f((i) * 480 / bigMapSize, (j) * 480 / bigMapSize);
            glVertex2f((i + 1) * 480 / bigMapSize, (j) * 480 / bigMapSize);
            glVertex2f((i + 1) * 480 / bigMapSize, (j + 1) * 480 / bigMapSize);
            glVertex2f((i) * 480 / bigMapSize, (j + 1) * 480 / bigMapSize);
        }

    glEnd();
    glutSwapBuffers();
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


