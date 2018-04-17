#include "localmap.h"

LocalMap::LocalMap():Map(5){
    centerX = 2;
    centerY = 2;
}

void LocalMap::isExistUNKNOWNzones(){

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(map[i][j] == WALL){
                //// В зависимости от того, где расположено препятствие
                /// рисовать невидимые участки
                // Сверху
                if((i == centerX)&&(j + 1 == centerY)){
                        map[i][j - 1] = UNKNOWN;
                        map[i + 1][j - 1] = UNKNOWN;
                        map[i - 1][j - 1] = UNKNOWN;
                }
                // Снизу
                if((i == centerX)&&(j - 1 == centerX)){
                        map[i][j + 1] = UNKNOWN;
                        map[i + 1][j + 1] = UNKNOWN;
                        map[i - 1][j + 1] = UNKNOWN;
                }
                // Справа
                if((i - 1 == centerX)&&(j == centerX)){
                        map[i + 1][j - 1] = UNKNOWN;
                        map[i + 1][j] = UNKNOWN;
                        map[i + 1][j + 1] = UNKNOWN;
                }
                //  Слева
                if((i + 1 == centerX)&&(j == centerX)){
                        map[i - 1][j - 1] = UNKNOWN;
                        map[i - 1][j] = UNKNOWN;
                        map[i - 1][j + 1] = UNKNOWN;
                }
                //  Верхняя правая диагональ
                if((i - 1 == centerX)&&(j + 1 == centerX)){
                        map[i + 1][j] = UNKNOWN;
                        map[i][j - 1] = UNKNOWN;
                        map[i + 1][j - 1] = UNKNOWN;
                }
                // Нижняя правая диагональ
                if((i - 1 == centerX)&&(j - 1 == centerX)){
                        map[i + 1][j] = UNKNOWN;
                        map[i][j + 1] = UNKNOWN;
                        map[i + 1][j + 1] = UNKNOWN;
                }
                // Верхняя левая диагональ
                if((i + 1 == centerX)&&(j + 1 == centerX)){
                        map[i - 1][j] = UNKNOWN;
                        map[i][j - 1] = UNKNOWN;
                        map[i - 1][j - 1] = UNKNOWN;
                }
                // Нижняя левая диагональ
                if((i + 1 == centerX)&&(j - 1 == centerX)){
                        map[i - 1][j] = UNKNOWN;
                        map[i][j + 1] = UNKNOWN;
                        map[i - 1][j + 1] = UNKNOWN;
                }

            }
}
