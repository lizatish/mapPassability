#include "localmap.h"

LocalMap::LocalMap():Map(5)

{
     heroCoordX = 2;
     heroCoordY = 2;

}





void LocalMap::isFindWALL(){

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(map[i][j] == WALL){
                //// В зависимости от того, где расположено препятствие
                /// рисовать невидимые участки
                // Сверху
                if((i == heroCoordX)&&(j + 1 == heroCoordY)){
                    // cout << "Up" << endl;

                    if(map[i][j - 1] != WALL)
                        map[i][j - 1] = UNKNOWN;
                    if(map[i + 1][j - 1] != WALL)
                        map[i + 1][j - 1] = UNKNOWN;
                    if(map[i - 1][j - 1] != WALL)
                        map[i - 1][j - 1] = UNKNOWN;
                }
                // Снизу
                if((i == heroCoordX)&&(j - 1 == heroCoordX)){
                    // cout << "Down" << endl;

                    if(map[i][j + 1] != WALL)
                        map[i][j + 1] = UNKNOWN;
                    if(map[i + 1][j + 1] != WALL)
                        map[i + 1][j + 1] = UNKNOWN;
                    if(map[i - 1][j + 1] != WALL)
                        map[i - 1][j + 1] = UNKNOWN;
                }
                // Справа
                if((i - 1 == heroCoordX)&&(j == heroCoordX)){
                    // cout << "Right" << endl;

                    if(map[i + 1][j - 1] != WALL)
                        map[i + 1][j - 1] = UNKNOWN;
                    if(map[i + 1][j] != WALL)
                        map[i + 1][j] = UNKNOWN;
                    if(map[i + 1][j + 1] != WALL)
                        map[i + 1][j + 1] = UNKNOWN;
                }
                //  Слева
                if((i + 1 == heroCoordX)&&(j == heroCoordX)){
                    //  cout << "Left" << endl;
                    if(map[i - 1][j - 1] != WALL)
                        map[i - 1][j - 1] = UNKNOWN;
                    if(map[i - 1][j] != WALL)
                        map[i - 1][j] = UNKNOWN;
                    if(map[i - 1][j + 1] != WALL)
                        map[i - 1][j + 1] = UNKNOWN;
                }
                //  Верхняя правая диагональ
                if((i - 1 == heroCoordX)&&(j + 1 == heroCoordX)){
                    //  cout << "Up right" << endl;

                    if(map[i + 1][j] != WALL)
                        map[i + 1][j] = UNKNOWN;
                    if(map[i][j - 1] != WALL)
                        map[i][j - 1] = UNKNOWN;
                    if(map[i + 1][j - 1] != WALL)
                        map[i + 1][j - 1] = UNKNOWN;
                }
                // Нижняя правая диагональ
                if((i - 1 == heroCoordX)&&(j - 1 == heroCoordX)){
                    //  cout << "Down right" << endl;

                    if(map[i + 1][j] != WALL)
                        map[i + 1][j] = UNKNOWN;
                    if(map[i][j + 1]!= WALL)
                        map[i][j + 1] = UNKNOWN;
                    if(map[i + 1][j + 1] != WALL)
                        map[i + 1][j + 1] = UNKNOWN;
                }

                // Верхняя левая диагональ
                if((i + 1 == heroCoordX)&&(j + 1 == heroCoordX)){
                    //  cout << "Up left" << endl;

                    if((map[i - 1][j] != WALL))
                        map[i - 1][j] = UNKNOWN;
                    if((map[i][j - 1] != WALL))
                        map[i][j - 1] = UNKNOWN;
                    if((map[i - 1][j - 1] != WALL))
                        map[i - 1][j - 1] = UNKNOWN;
                }
                // Нижняя левая диагональ
                if((i + 1 == heroCoordX)&&(j - 1 == heroCoordX)){
                    //   cout << "Down left" << endl;
                    if((map[i - 1][j] != WALL))
                        map[i - 1][j] = UNKNOWN;
                    if((map[i][j + 1]!= WALL))
                        map[i][j + 1] = UNKNOWN;
                    if((map[i - 1][j + 1] != WALL))
                        map[i - 1][j + 1] = UNKNOWN;
                }

            }

}
