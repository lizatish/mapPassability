#ifndef LOCALMAP_H
#define LOCALMAP_H

#include "map.h"
#include "globalmap.h"


class LocalMap : public Map {
private:
    // Текущие координаты героя [всегда одинаковы]
    int heroCoordX;
    int heroCoordY;
public:
    LocalMap();

    // Проверка на наличие невидимых зон
    void isExistUNKNOWNzones();
};

#endif // LOCALMAP_H
