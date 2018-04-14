#ifndef GLOBALMAP_H
#define GLOBALMAP_H

#include "map.h"

class GlobalMap : public Map
{
public:
    GlobalMap();
    GlobalMap(int glSize);

    // Задать карту по умолчанию [рандомная карта]
    void setGlobalMap();
    // Задать карту вручную
    void setGlobalMap(int** glMap);
};

#endif // GLOBALMAP_H
