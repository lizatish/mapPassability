#ifndef LOCALMAP_H
#define LOCALMAP_H

#include "map.h"
#include "globalmap.h"


class LocalMap : public Map {
private:
    // Текущие координаты героя [условно]
    int centerX;
    int centerY;
public:
    LocalMap();

    // Проверка на наличие невидимых зон
    void isExistUNKNOWNzones();
};

#endif // LOCALMAP_H
