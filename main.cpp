#include "robot.h"
#include "display.h"
#include "globalmap.h"
#include "navigator.h"
#include "mainwindow.h"
#include "node.h"
#include "astarsearch.h"
#include <QApplication>

int** myMap;

int main(int argc, char *argv[])
{
    vector<pair<int, int> > resDirection;

    int heroCoordX = 1;
    int heroCoordY = 1;
    int exitCoordX = 18;
    int exitCoordY = 18;

    // Создание глобальной карты
    GlobalMap* GM;
    // В аргемунте конструктора - размер карты
    GM = new GlobalMap(20);

    // Создание навигатора
    Navigator* NV;
    NV = new Navigator(GM);
    // Установить текущее местоположение
    NV->setCoordinates(heroCoordX, heroCoordY);
    NV->setExit(exitCoordX, exitCoordY);

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

    vector<pair<int, int>> path;

    // Получение текущей открытой карты
    OM = robotic->showSituation();
    int** omap = OM->getMap();
    myMap = omap;
    w.setMap(myMap);

    // Отображение
    DISP->display(OM);
    AStarSearch* AS;
    AS = new AStarSearch();

    while(1){

        if(heroCoordX == exitCoordX && heroCoordY == exitCoordY)
            break;
        resDirection = AS->pathFind(heroCoordX, heroCoordY, exitCoordX, exitCoordY, myMap);

        for (vector<pair<int, int> >::iterator k = resDirection.end() - 1; k != resDirection.begin() - 1; --k){

            int nx = k -> first;
            int ny = k -> second;
            //  myMap[nx][ny] = 1;

            if(nx - heroCoordX == -1){
                if(ny - heroCoordY == 1){
                    robotic->goDiaDL();
                }
                else if(ny - heroCoordY == -1){
                    robotic->goDiaUL();
                }
                else
                    robotic->goLeft();

            }
            else if(nx - heroCoordX == 1){
                if(ny - heroCoordY == 1){
                    robotic->goDiaDR();
                }
                else if(ny - heroCoordY == -1){
                    robotic->goDiaUR();
                }
                else
                    robotic->goRight();
            }
            else if(ny - heroCoordY == 1){
                robotic->goDown();
            }
            else if(ny - heroCoordY == -1){
                robotic->goUp();
            }
            heroCoordX = NV->getHeroCoordX();
            heroCoordY = NV->getHeroCoordY();

            break;
        }


        //            // Получение текущей открытой карты
        OM = robotic->showSituation();
        omap = OM->getMap();
        myMap = omap;
        path = OM->getPath();

        // Посылка в rviz
        w.setMap(myMap);
        w.setPath(path);

        // Отображение
        DISP->display(OM);
        usleep(500000);
    }

    usleep(10000000000);

    return a.exec();
}


