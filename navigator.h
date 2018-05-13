#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include"localmap.h"
#include"globalmap.h"


class Navigator
{
private:
    // Объект для хранения локальной карты
    LocalMap* LM;
    // Текущая локальная карта
    int** locMap;
    // Размер локальной карты
    int locMapSize;

    int exitCoordX;
    int exitCoordY;
    // Глобальная карта
    int** globMap;
    // Размер глобальной карты
    int globMapSize;
    // Текущие глобальные координаты
    int globHeroX;
    int globHeroY;

public:
    Navigator(GlobalMap* GM);

    // Установка текущего местонахождения героя
    void setCoordinates(int x, int y);

    void setExit(int x, int y);


    // Поиск текущего местонахождения робота на глобальной карте
    LocalMap* findRobotOnGlobalMap();

    // Изменить координаты в зависимости от того, куда робот пошел
    void goUp();
    void goDown();
    void goLeft();
    void goRight();

    void goDiaUR();
    void goDiaUL();
    void goDiaDR();
    void goDiaDL();

    // Get-теры
    int getHeroCoordX() const;
    int getHeroCoordY() const;
    int getExitCoordX() const;
    int getExitCoordY() const;
    int getGlobalMapSize() const;
};

#endif // NAVIGATOR_H
