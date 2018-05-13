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

    int exitCoordX;
    int exitCoordY;

    const int EXIT = -20;
    // Хранилище координат пройденного пути
    vector <pair<int, int>> path;

public:
    OpenMap(int initSize, int heroX, int heroY);
    OpenMap(int initSize, int heroX, int heroY, int exX, int exY);

    // Свободна ли ячейка, куда мы хоти переместиться
    bool isFreeGoRight();
    bool isFreeGoLeft();
    bool isFreeGoUp();
    bool isFreeGoDown();

    bool isFreeGoDiaUL();
    bool isFreeGoDiaUR();
    bool isFreeGoDiaDR();
    bool isFreeGoDiaDL();

    // Идти в указанном направлении
    void goUp();
    void goDown();
    void goLeft();
    void goRight();

    void goDiaUL();
    void goDiaUR();
    void goDiaDL();
    void goDiaDR();



    // Соединение текущую локальнку и открытую карты
    void connectOpenAndLocalMap(LocalMap* LM);

    // Проверка на наложение текущей локальной и открытой карт
    void checkForOverloadingCells(LocalMap* LM);

    // Get-теры
    int getHeroCoordX() const;
    int getHeroCoordY() const;
    int getExitCoordX() const;
    int getExitCoordY() const;
    vector<pair<int, int> > getPath() const;
    int getEXIT() const;
};


#endif // OPENMAP_H
