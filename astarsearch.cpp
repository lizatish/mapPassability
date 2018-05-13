#include "astarsearch.h"

AStarSearch::AStarSearch()
{
    open_nodes_map = new int* [N];
    for(int i = 0; i < N; i++){
        open_nodes_map[i] = new int[N];
    }
    closed_nodes_map = new int* [N];
    for(int i = 0; i < N; i++){
        closed_nodes_map[i] = new int[N];
    }
    dir_map = new int* [N];
    for(int i = 0; i < N; i++){
        dir_map[i] = new int[N];
    }

    dx = new int [dir];
    dy = new int [dir];

    dx[0] = 1;
    dx[1] = 1;
    dx[2] = 0;
    dx[3] = -1;
    dx[4] = -1;
    dx[5] = -1;
    dx[6] = 0;
    dx[7] = 1;

    dy[0] = 0;
    dy[1] = 1;
    dy[2] = 1;
    dy[3] = 1;
    dy[4] = 0;
    dy[5] = -1;
    dy[6] = -1;
    dy[7] = -1;

}
vector<pair<int, int>> AStarSearch::checkOnEnd(){
    // Сгенерировать путь от финиша до старта
    // следуя направлению
    int j;
    vector<pair<int, int> > rDir;
    while(1)
    {
        if(x == startX && y == startY)
            break;
        j = dir_map[x][y];
        rDir.push_back(pair<int, int>(x, y));
        x += dx[j];
        y += dy[j];
    }
    // Удаление мусора
    delete n0;
    // Очистить оставшиеся узлы
    while(!pq[pqi].empty())
        pq[pqi].pop();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << dir_map[i][j];
        cout << endl;
    }
cout << "**********************************" << endl;
    return rDir;
}

vector<pair<int, int>> AStarSearch::pathFind( const int & xStart, const int & yStart,
                                              const int & xFinish, const int & yFinish, int** myMap )
{
    resDir.clear();
    startX = xStart;
    startY = yStart;
    // Обуление карт с узлами
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            closed_nodes_map[i][j] = 0;
            open_nodes_map[i][j] = 0;
            dir_map[i][j] = 0;
        }
    }

    // Создание начального узла и добавление его в очередь открытых узлов
    n0 = new Node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pqi].push(*n0);
    open_nodes_map[N - 1][N - 1] = n0->getPriority(); // Пометить его на карте открытых узлов

    // A* поиск
    while(!pq[pqi].empty())
    {
        // Получить текущий узел с самым высоким приорритетом
        // из очереди с открытыми узлами
        n0 = new Node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
                       pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x = n0->getxPos();
        y = n0->getyPos();

        pq[pqi].pop(); // Достать узел из очереди
        open_nodes_map[x][y] = 0;
        // Записать узел в карту закрытых узлов
        closed_nodes_map[x][y] = 1;

        // Прекратить поиск, когда достигнуто состояние цели :
        // if((*n0).estimate(xFinish, yFinish) == 0)
        if(x == xFinish && y == yFinish)
        {
            return resDir = checkOnEnd();
        }

        // Создание всех возможных направлений движения ( дочерних узлов )
        for(int i = 0; i < dir; i++)
        {
            xdx = x + dx[i]; ydy = y + dy[i];

            if(!(xdx < 0 || xdx > N-1 || ydy < 0 || ydy > N - 1 || myMap[xdx][ydy] == 100
                /* || myMap[xdx][ydy] == 1 *//*|| myMap[xdx][ydy] == 50*/
                 || closed_nodes_map[xdx][ydy] == 1))
            {
                // Создание дочернего узла
                m0 = new Node( xdx, ydy, n0->getLevel(), n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xFinish, yFinish);

                // Если он находится в открытом списке, тогда
                if(open_nodes_map[xdx][ydy] == 0 )
                {
                    open_nodes_map[xdx][ydy] = m0->getPriority();
                    pq[pqi].push(*m0);
                    // Записать направление его родительского узла
                    dir_map[xdx][ydy] = (i + dir / 2) % dir;

                }
                else if(open_nodes_map[xdx][ydy] > m0->getPriority())
                {
                    //Обновить приоритетную информацию
                    open_nodes_map[xdx][ydy] = m0->getPriority();
                    //Обновить направление родительского направления
                    dir_map[xdx][ydy] = (i + dir / 2) % dir;


                    // Заменим узел опуская один pq за другим,
                    // за исключением того, что узел, который будет заменен, будет проигнорирован
                    // и вместо этого будет вставлен новый узел
                    while(!(pq[pqi].top().getxPos() == xdx && pq[pqi].top().getyPos() == ydy))
                    {
                        pq[1 - pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pq[pqi].pop(); // Удаляем требуемый узел

                    // Опускаем размер pq до меньшего размера
                    if(pq[pqi].size() > pq[1 - pqi].size()) pqi = 1 - pqi;
                    while(!pq[pqi].empty())
                    {
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pqi = 1 - pqi;
                    pq[pqi].push(*m0); // Добавить лучший узел
                }
                else delete m0;
            }
        }
        delete n0;
    }
    exit(1); // Путь не найден
}



// Determine priority (in the priority queue)
bool operator<(const Node & a, const Node & b)
{
    return a.getPriority() > b.getPriority();
}
