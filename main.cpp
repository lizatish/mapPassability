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

    vector<int> map{100, 100, 100, 100,
                    50, 50, 50, 50,
                    0, 0, 0, 0,
                    100, 100, 100, 100};
    w.setMap(map);

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
    return a.exec();
}
