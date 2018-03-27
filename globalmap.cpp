#include "globalmap.h"

int globalMap::getUNKNOWN() const
{
    return UNKNOWN;
}

int globalMap::getExitCoordY() const
{
    return exitCoordY;
}

int globalMap::getExitCoordX() const
{
    return exitCoordX;
}

int globalMap::getHeroCoordY() const
{
    return heroCoordY;
}

int globalMap::getHeroCoordX() const
{
    return heroCoordX;
}

int globalMap::getEXIT() const
{
    return EXIT;
}

int globalMap::getHERO() const
{
    return HERO;
}

int globalMap::getWALL() const
{
    return WALL;
}

int globalMap::getLocalMapSize() const
{
    return localMapSize;
}

int globalMap::getBigMapSize() const
{
    return bigMapSize;
}

int **globalMap::getMap() const
{
    return map;
}


int **globalMap::getLocalMap() const
{
    return localMap;
}


int **globalMap::getCurrentMap() const
{
    return currentMap;
}

int globalMap::getVISIBLE() const
{
    return VISIBLE;
}
int globalMap::getWasThere() const
{
    return WAS_THERE;
}


globalMap::globalMap()
{
    // Наша начальная позиция
    heroCoordX = 10;
    heroCoordY = 10;
    prevHeroCoordX = heroCoordX;
    prevHeroCoordY = heroCoordY;

    map = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        map[i] = new int[bigMapSize];
    }
    localMap = new int* [localMapSize];
    for(int i = 0; i < localMapSize; i++){
        localMap[i] = new int[localMapSize];
    }
    prevLocalMap = new int* [localMapSize];
    for(int i = 0; i < localMapSize; i++){
        prevLocalMap[i] = new int[localMapSize];
    }

    currentMap = new int* [bigMapSize];
    for(int i = 0; i < bigMapSize; i++){
        currentMap[i] = new int[bigMapSize];
    }

    prevPath = "";
}



void globalMap::isFindWALL(){

    connectGlobalAndLocalMap();

    for(int i = 0; i < localMapSize; i++)
        for(int j = 0; j < localMapSize; j++)
            if(localMap[i][j] == WALL){
                //// В зависимости от того, где расположено препятствие
                /// рисовать невидимые участки
                // Сверху
                if((i == localHeroX)&&(j + 1 == localHeroY)){
                    cout << "Up" << endl;

                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                }
                // Снизу
                if((i == localHeroX)&&(j - 1 == localHeroY)){
                    cout << "Down" << endl;

                    if(localMap[i][j + 1] != WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }
                // Справа
                if((i - 1 == localHeroX)&&(j == localHeroY)){
                    cout << "Right" << endl;

                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                }
                //  Слева
                if((i + 1 == localHeroX)&&(j == localHeroY)){
                    cout << "Left" << endl;
                    if(localMap[i - 1][j - 1] != WALL)
                        localMap[i - 1][j - 1] = UNKNOWN;
                    if(localMap[i - 1][j] != WALL)
                        localMap[i - 1][j] = UNKNOWN;
                    if(localMap[i - 1][j + 1] != WALL)
                        localMap[i - 1][j + 1] = UNKNOWN;
                }
                //  Верхняя правая диагональ
                if((i - 1 == localHeroX)&&(j + 1 == localHeroY)){
                    cout << "Up right" << endl;

                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i][j - 1] != WALL)
                        localMap[i][j - 1] = UNKNOWN;
                    if(localMap[i + 1][j - 1] != WALL)
                        localMap[i + 1][j - 1] = UNKNOWN;
                }
                // Нижняя правая диагональ
                if((i - 1 == localHeroX)&&(j - 1 == localHeroY)){
                    cout << "Down right" << endl;

                    if(localMap[i + 1][j] != WALL)
                        localMap[i + 1][j] = UNKNOWN;
                    if(localMap[i][j + 1]!= WALL)
                        localMap[i][j + 1] = UNKNOWN;
                    if(localMap[i + 1][j + 1] != WALL)
                        localMap[i + 1][j + 1] = UNKNOWN;
                }

                // Верхняя левая диагональ
                if((i + 1 == localHeroX)&&(j + 1 == localHeroY)){
                    cout << "Up left" << endl;

                    if((localMap[i - 1][j] != WALL)
                            )
                        localMap[i - 1][j] = UNKNOWN;
                    if((localMap[i][j - 1] != WALL)
                            )
                        localMap[i][j - 1] = UNKNOWN;
                    if((localMap[i - 1][j - 1] != WALL)
                            )
                        localMap[i - 1][j - 1] = UNKNOWN;
                }
                // Нижняя левая диагональ
                if((i + 1 == localHeroX)&&(j - 1 == localHeroY)){
                    cout << "Down left" << endl;
                    if((localMap[i - 1][j] != WALL)
                            )
                        localMap[i - 1][j] = UNKNOWN;
                    if((localMap[i][j + 1]!= WALL)
                            )
                        localMap[i][j + 1] = UNKNOWN;
                    if((localMap[i - 1][j + 1] != WALL)
                            )
                        localMap[i - 1][j + 1] = UNKNOWN;
                }

            }
    if(n >= 1){
        // Проверка на пересекаемые зоны предыдущей версии карты и только что открытой
        checkForOverloadingCells();
    }
    n++;

    prevLocalMap = localMap;

    // Нарисовать на текущей открытой карте то, что только что увидели
    connectCurrentAndLocalMap();

}
void globalMap::connectCurrentAndLocalMap(){
    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;
    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            currentMap[x][y++] = localMap[i][j];
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
    }
}

void globalMap::connectGlobalAndLocalMap(){
    int x = heroCoordX - (localMapSize - 1) / 2;
    int y = heroCoordY - (localMapSize - 1) / 2;

    for(int i = 0; i < localMapSize; i++){
        for(int j = 0; j < localMapSize; j++){
            localMap[i][j] = map[x][y++];
        }
        x++;
        y = heroCoordY - (localMapSize - 1) / 2;
    }
}

void globalMap::setGlobalMap(){

    srand(time(NULL));
    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j)
        {
            if (rand() % 4 == 0)
                map[i][j] = WALL;
            else
                map[i][j] = VISIBLE;
        }
    for (int i = 0; i < bigMapSize; ++i)
    {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][bigMapSize - 1] = WALL;
        map[bigMapSize - 1][i] = WALL;
    }
    map[heroCoordX][heroCoordY] = HERO;
    map[exitCoordX][exitCoordY] = EXIT;

    for (int i = 0; i < bigMapSize; ++i)
        for (int j = 0; j < bigMapSize; ++j){
            currentMap[i][j] = UNKNOWN;
        }
}

void globalMap::findNextStep(){

    prevHeroCoordX = heroCoordX;
    prevHeroCoordY = heroCoordY;

    pathX.push_back(heroCoordX);
    pathY.push_back(heroCoordY);

//    int randomNumber;
//    srand(time(NULL));

//    // Если стенка справа
//    if((map[heroCoordX + 1][heroCoordY] == WALL || WAS_THERE)
//            &&(map[heroCoordX - 1][heroCoordY] == VISIBLE )
//            &&(map[heroCoordX][heroCoordY + 1] == VISIBLE)
//            && (map[heroCoordX][heroCoordY - 1] == VISIBLE)){
//        randomNumber =  1 + rand() % 3;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO DOWN" << endl;
//            prevPath = "Down";
//            heroCoordY++;
//            break;
//        }
//        case 2:{
//            cout << "GO UP" << endl;
//            prevPath = "Up";
//            heroCoordY--;
//            break;
//        }

//        case 3:{
//            cout << "GO LEFT" << endl;
//            prevPath = "Left";
//            heroCoordX--;
//            break;

//        }
//        }
//    }
//    // Если стенка слева
//    else if((map[heroCoordX - 1][heroCoordY] == WALL || WAS_THERE)
//            &&(map[heroCoordX + 1][heroCoordY] == VISIBLE)
//            &&(map[heroCoordX][heroCoordY + 1] == VISIBLE)
//            && (map[heroCoordX][heroCoordY - 1] == VISIBLE)){

//        randomNumber =  1 + rand() % 3;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO DOWN" << endl;
//            prevPath = "Down";
//            heroCoordY++;
//            break;

//        }
//        case 2:{
//            cout << "GO UP" << endl;
//            prevPath = "Up";
//            heroCoordY--;
//            break;

//        }
//        case 3:{
//            cout << "GO RIGHT" << endl;
//            prevPath = "Right";
//            heroCoordX++;
//            break;

//        }
//        }
//    }
//    // Если стенка снизу
//    else if((map[heroCoordX][heroCoordY + 1] == WALL || WAS_THERE)
//            &&(map[heroCoordX + 1][heroCoordY] == VISIBLE )
//            &&(map[heroCoordX - 1][heroCoordY] == VISIBLE)
//            && (map[heroCoordX][heroCoordY - 1] == VISIBLE)){

//        randomNumber =  1 + rand() % 3;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO LEFT" << endl;
//            prevPath = "Left";
//            heroCoordX--;
//            break;

//        }
//        case 2:{
//            cout << "GO UP" << endl;
//            prevPath = "Up";
//            heroCoordY--;
//            break;

//        }
//        case 3:{
//            cout << "GO RIGHT" << endl;
//            prevPath = "Right";
//            heroCoordX++;
//            break;

//        }
//        }
//    }
//    // Если стенка сверху
//    else if((map[heroCoordX][heroCoordY - 1] == WALL || WAS_THERE)
//            &&(map[heroCoordX + 1][heroCoordY] == VISIBLE)
//            &&(map[heroCoordX - 1][heroCoordY] == VISIBLE)
//            && (map[heroCoordX][heroCoordY + 1] == VISIBLE)){

//        randomNumber =  1 + rand() % 3;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO DOWN" << endl;
//            prevPath = "Down";
//            heroCoordY++;
//            break;

//        }
//        case 2:{
//            cout << "GO LEFT" << endl;
//            prevPath = "Left";
//            heroCoordX--;
//            break;

//        }
//        case 3:{
//            cout << "GO RIGHT" << endl;
//            prevPath = "Right";
//            heroCoordX++;
//            break;

//        }
//        }
//    }
//    // Стенки справа и слева
//    else if((map[heroCoordX][heroCoordY - 1] == VISIBLE)
//            &&(map[heroCoordX + 1][heroCoordY] == WALL || WAS_THERE)
//            &&(map[heroCoordX - 1][heroCoordY] == WALL || WAS_THERE)
//            && (map[heroCoordX][heroCoordY + 1] == VISIBLE)){
//        randomNumber =  1 + rand() % 2;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO DOWN" << endl;
//            prevPath = "Down";
//            heroCoordY++;
//            break;

//        }
//        case 2:{
//            cout << "GO UP" << endl;
//            prevPath = "Up";
//            heroCoordY--;
//            break;
//        }

//        }
//    }
//    // Стенки снизу и сверху
//    else if((map[heroCoordX][heroCoordY - 1] == WALL || WAS_THERE)
//            &&(map[heroCoordX + 1][heroCoordY] == VISIBLE)
//            &&(map[heroCoordX - 1][heroCoordY] == VISIBLE)
//            && (map[heroCoordX][heroCoordY + 1] == WALL || WAS_THERE)){
//        randomNumber =  1 + rand() % 2;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO LEFT" << endl;
//            prevPath = "Left";
//            heroCoordX--;
//            break;

//        }
//        case 2:{
//            cout << "GO RIGHT" << endl;
//            prevPath = "Right";
//            heroCoordX++;
//            break;

//        }

//        }
//    }
//    // Стенки сверху и слева
//    else if((map[heroCoordX][heroCoordY - 1] == WALL || WAS_THERE)
//            &&(map[heroCoordX + 1][heroCoordY] == VISIBLE)
//            &&(map[heroCoordX - 1][heroCoordY] == WALL || WAS_THERE)
//            && (map[heroCoordX][heroCoordY + 1] == VISIBLE)){
//        randomNumber =  1 + rand() % 2;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO DOWN" << endl;
//            prevPath = "Down";
//            heroCoordY++;
//            break;
//        }

//        case 2:{
//            cout << "GO RIGHT" << endl;
//            prevPath = "Right";
//            heroCoordX++;
//            break;

//        }

//        }
//        // Стенки сверху и справа
//    }
//    else if((map[heroCoordX][heroCoordY - 1] == WALL || WAS_THERE)
//            &&(map[heroCoordX + 1][heroCoordY] == WALL || WAS_THERE)
//            &&(map[heroCoordX - 1][heroCoordY] == VISIBLE)
//            && (map[heroCoordX][heroCoordY + 1] == VISIBLE)){
//        randomNumber =  1 + rand() % 2;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO DOWN" << endl;
//            prevPath = "Down";
//            heroCoordY++;
//            break;
//        }
//        case 2:{
//            cout << "GO LEFT" << endl;
//            prevPath = "Left";
//            heroCoordX--;
//            break;

//        }

//        }
//    }
//    // Стенки снизу и справа
//    else if((map[heroCoordX][heroCoordY + 1] == WALL || WAS_THERE)
//            &&(map[heroCoordX + 1][heroCoordY] == WALL || WAS_THERE)
//            &&(map[heroCoordX - 1][heroCoordY] == VISIBLE)
//            && (map[heroCoordX][heroCoordY - 1] == VISIBLE)){
//        randomNumber =  1 + rand() % 2;
//        switch(randomNumber){

//        case 1:{
//            cout << "GO LEFT" << endl;
//            prevPath = "Left";
//            heroCoordX--;
//            break;

//        }

//        case 2:{
//            cout << "GO UP" << endl;
//            prevPath = "Up";
//            heroCoordY--;
//            break;

//        }
//        }
//    }
//    // Стенки снизу и слева
//    else if((map[heroCoordX][heroCoordY - 1] == VISIBLE)
//            &&(map[heroCoordX + 1][heroCoordY]== VISIBLE)
//            &&(map[heroCoordX - 1][heroCoordY] == WALL || WAS_THERE)
//            && (map[heroCoordX][heroCoordY + 1] == WALL || WAS_THERE)){
//        randomNumber =  1 + rand() % 2;
//        switch(randomNumber){

//        case 1:{
//            cout << "GO RIGHT" << endl;
//            prevPath = "Right";
//            heroCoordX++;
//            break;

//        }
//        case 2:{
//            cout << "GO UP" << endl;
//            prevPath = "Up";
//            heroCoordY--;
//            break;

//        }
//        }
//    }
//    // Стеки справа, слева и сверху
//    // Стенки справа, слева и снизу
//    // Стенки сверху, снизу и справа
//    //Стенки сверху, снизу и слева

//    // Если стенок нет
//    else{
//        randomNumber =  1 + rand() % 4;
//        switch(randomNumber){
//        case 1:
//        {
//            cout << "GO DOWN" << endl;
//            prevPath = "Down";
//            heroCoordY++;
//            break;
//        }
//        case 2:{
//            cout << "GO LEFT" << endl;
//            prevPath = "Left";
//            heroCoordX--;
//            break;

//        }
//        case 3:{
//            cout << "GO RIGHT" << endl;
//            prevPath = "Right";
//            heroCoordX++;
//            break;

//        }
//        case 4:{
//            cout << "GO UP" << endl;
//            prevPath = "Up";
//            heroCoordY--;
//            break;

//        }
//        }
//    }
        // Низ
        if((map[heroCoordX][heroCoordY + 1] != WALL)&&(map[heroCoordX][heroCoordY + 1] != UNKNOWN)){
            cout << "GO DOWN" << endl;
            prevPath = "Down";
            heroCoordY++;
        }

        // Право
        else if((map[heroCoordX + 1][heroCoordY] != WALL)&&(map[heroCoordX + 1][heroCoordY] != UNKNOWN)){
            cout << "GO RIGHT" << endl;
            prevPath = "Right";
            heroCoordX++;
        }

        // Верх
        else if((map[heroCoordX][heroCoordY - 1] != WALL)&&(map[heroCoordX][heroCoordY - 1] != UNKNOWN)){
            cout << "GO UP" << endl;
            prevPath = "Up";
            heroCoordY--;

        }

        // Лево
        else if((map[heroCoordX - 1][heroCoordY] != WALL)&&(map[heroCoordX - 1][heroCoordY] != UNKNOWN)){
            cout << "GO LEFT" << endl;
            prevPath = "Left";
            heroCoordX--;

        }
    currentMap[heroCoordX][heroCoordY] = HERO;




    for(int i = 0; i < pathX.size(); i++){
        map[pathX[i]][pathY[i]] = WAS_THERE;
    }


}



void globalMap::checkForOverloadingCells(){


    int x = prevHeroCoordX - (localMapSize - 1) / 2;
    int y = prevHeroCoordY - (localMapSize - 1) / 2;

    if(prevPath == "Right"){
        x += 1;
        for(int i = 0; i < localMapSize - 1; i++){
            for(int j = 0; j < localMapSize; j++){
                if((currentMap[x][y] == VISIBLE)&&(localMap[i][j] == UNKNOWN))
                    localMap[i][j] = VISIBLE;
                else if((currentMap[x][y] == WAS_THERE)&&(localMap[i][j] == UNKNOWN))
                    localMap[i][j] = WAS_THERE;
                y++;
            }
            x++;
            y = prevHeroCoordY - (localMapSize - 1) / 2;
        }
    }
    else if(prevPath == "Left"){
        x -= 1;

        for(int i = 0; i < localMapSize - 1; i++){
            for(int j = 0; j < localMapSize; j++){
                if((currentMap[x][y] == VISIBLE)&&(localMap[i][j] == UNKNOWN))
                    localMap[i][j] = VISIBLE;
                else if((currentMap[x][y] == WAS_THERE)&&(localMap[i][j] == UNKNOWN))
                    localMap[i][j] = WAS_THERE;
                y++;
            }
            x++;
            y = prevHeroCoordY - (localMapSize - 1) / 2;

        }
    }
    else if(prevPath == "Down"){
        y++;
        for(int i = 0; i < localMapSize; i++){
            for(int j = 0; j < localMapSize - 1; j++){
                if((currentMap[x][y] == VISIBLE)&&(localMap[i][j] == UNKNOWN))
                    localMap[i][j] = VISIBLE;
                else if((currentMap[x][y] == WAS_THERE)&&(localMap[i][j] == UNKNOWN))
                    localMap[i][j] = WAS_THERE;
                y++;
            }
            x++;
            y = prevHeroCoordY - (localMapSize - 1) / 2 + 1;

        }
    }
    else if(prevPath == "Up"){
        y--;
        for(int i = 0; i < localMapSize; i++){
            for(int j = 0; j < localMapSize - 1; j++){
                if((currentMap[x][y] == VISIBLE)&&(localMap[i][j] == UNKNOWN))
                    localMap[i][j] = VISIBLE;
                else if((currentMap[x][y] == WAS_THERE)&&(localMap[i][j] == UNKNOWN))
                    localMap[i][j] = WAS_THERE;
                y++;
            }
            x++;
            y = prevHeroCoordY - (localMapSize - 1) / 2 - 1;

        }
    }
}
