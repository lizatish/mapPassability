#ifndef DISPLAY_H
#define DISPLAY_H

#include <openmap.h>

class Display
{
private:
    // Размер открытой карты
    int openMapSize;

    // Текущие координаты
    int heroCoordX;
    int heroCoordY;

    // Текущая карта
    int** map;
public:
    Display();

    // Отображение открытой карты
    void display(OpenMap* OM);

};

#endif // DISPLAY_H
