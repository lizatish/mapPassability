#ifndef ROBOT_H
#define ROBOT_H

#include "navigator.h"
#include "openmap.h"
#include "globalmap.h"
#include "localmap.h"
#include "display.h"

class Robot
{
private:
    // Объект открытой карты
    OpenMap* OM;
    // Объект навигатора
    Navigator* NTR;

    // Свободна ли ячейка, куда мы хотим переместиться
    bool isFreeNeedCell;
public:
    Robot(Navigator* initNav);

    // Показать текущее местонахождение
    OpenMap* showSituation();

    // Создание открытой карты
    void connectOpenMap();

    // Идти в нужном направдении
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
};

#endif // ROBOT_H
