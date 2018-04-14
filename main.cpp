#include "robot.h"
#include "display.h"
#include "globalmap.h"
#include "navigator.h"

int main()
{   
    // Создание глобальной карты
    GlobalMap* GM;
    // В аргемунте конструктора - размер карты
    GM = new GlobalMap(20);
    GM->setGlobalMap();

    // Создание навигатора
    Navigator* NV;
    NV = new Navigator(GM);
    // Установить текущее местоположение
    NV->setCoordinates(18, 1);

    // Создание робота
    Robot* robotic;
    // Загружаем в робота навигатор
    robotic = new Robot(NV);

    // Создание открытой карты
    OpenMap* OM;
    // Создание визуализации
    Display* DISP;
    DISP = new Display();

    // Получение текущей открытой карты
    OM = robotic->showSituation();
    // Отображение
    DISP->display(OM);

    while(1){
        char ch;
        cin >> ch;

        switch(ch){
        case 'w': {
            // Робот идет вперед
            robotic->goUp();
            break;}
        case 'a': {
            // Робот идет влево
            robotic->goLeft();
            break;}
        case 's': {
            // Робот идет вниз
            robotic->goDown();
            break;}
        case 'd': {
            // Робот идет вправо
            robotic->goRight();
            break;
        }
        }
        // Получение текущей открытой карты
        OM = robotic->showSituation();
        // Отображение
        DISP->display(OM);
    }
    return 0;
}
