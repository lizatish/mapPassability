#include <robot.h>
#include <globalmap.h>

int main()
{
    GlobalMap* GM;

    Robot* robotic;
    robotic = new Robot();

    robotic->showSituation();


    while(1){
        char ch;
        ch = getchar();
        robotic->showSituation();

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
    }
    return 0;
}
