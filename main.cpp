#include "robot.h"
#include "display.h"
#include "globalmap.h"
#include "navigator.h"
#include "mainwindow.h"


#include <QApplication>


int main(int argc, char *argv[])
{
    // Создание глобальной карты
    GlobalMap* GM;
    // В аргемунте конструктора - размер карты
    GM = new GlobalMap(20);

    // Создание навигатора
    Navigator* NV;
    NV = new Navigator(GM);
    // Установить текущее местоположение
    NV->setCoordinates(4, 7);

    // Создание робота
    Robot* robotic;
    // Загружаем в робота навигатор
    robotic = new Robot(NV);

    // Создание открытой карты
    OpenMap* OM;
    // Создание визуализации
    Display* DISP;
    DISP = new Display();

    QApplication a(argc, argv);
    MainWindow w;

    vector<int> map;


    // Получение текущей открытой карты
    OM = robotic->showSituation();

    int** omap = OM->getMap();

    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            map.push_back(omap[i][j]);

    w.setMap(map);
    map.clear();

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
        omap = OM->getMap();

            for(int i = 0; i < 20; i++)
                for(int j = 0; j < 20; j++)
                    map.push_back(omap[i][j]);

            w.setMap(map);
            map.clear();

        // Отображение
        DISP->display(OM);
    }
    return a.exec();
}
