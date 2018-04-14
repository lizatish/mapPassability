#ifndef OPENMAP_H
#define OPENMAP_H

#include "map.h"
#include "globalmap.h"
#include "localmap.h"


class OpenMap : public Map {
private:
    // Хранение текущей локальной карты
    LocalMap* LM;

    // Текущие координаты героя
    int heroCoordX;
    int heroCoordY;

    // Хранилище координат пройденного пути
    vector <int> pathX;
    vector <int> pathY;

    bool isFirstCall;

public:
    OpenMap(int initSize, int heroX, int heroY);

    // Свободна ли ячейка, куда мы хоти переместиться
    bool isFreeGoRight();
    bool isFreeGoLeft();
    bool isFreeGoUp();
    bool isFreeGoDown();

    // Идти в указанном направлении
    void goUp();
    void goDown();
    void goLeft();
    void goRight();

    // Соединение текущую локальнку и открытую карты
    void connectOpenAndLocalMap(LocalMap* LM);

    // Проверка на наложение текущей локальной и открытой карт
    void checkForOverloadingCells(LocalMap* LM);

    // Get-теры
    int getHeroCoordX() const;
    int getHeroCoordY() const;
};


#endif // OPENMAP_H
