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

    void goDiaUR();
    void goDiaUL();
    void goDiaDR();
    void goDiaDL();
};

#endif // ROBOT_H
