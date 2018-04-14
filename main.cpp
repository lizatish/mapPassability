#include "robot.h"
#include "display.h"
#include "globalmap.h"
#include "navigator.h"

int main()
{   
    GlobalMap* GM;
    GM = new GlobalMap(20);
    GM->setGlobalMap();    

    Navigator* NV;
    NV = new Navigator(GM);
    NV->setCoordinates(18, 1);

    Robot* robotic;
    robotic = new Robot(NV);

    OpenMap* OM;
    Display* DISP;
    DISP = new Display();
    OM = robotic->showSituation();
    DISP->display(OM);

    while(1){
        char ch;
        cin >> ch;


        switch(ch){
        case 'w': {
            robotic->goUp();
            break;}
        case 'a': {
            robotic->goLeft();
            break;}
        case 's': {
            robotic->goDown();
            break;}
        case 'd': {
            robotic->goRight();
            break;
        }
        }
        OM = robotic->showSituation();
        DISP->display(OM);


    }
    return 0;
}
