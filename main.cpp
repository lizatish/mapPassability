#include <iostream>
#include <iomanip>
#include <vector>
#include <GL/glut.h>
#include <chrono>
#include <thread>
#include <math.h>
#include <queue>
#include <ctime> // содержит time()
using namespace std::this_thread;     // sleep_for, sleep_until
using std::chrono::system_clock;
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;
void display();
const int N = 30;
const int WALL = 55;
const int HERO = -1;
const int EXIT = -8;
const int heroCoordX = 3;
const int heroCoordY = 6;
int exitCoordX = 20;
int exitCoordY = 20;


int map[N][N];
static int closed_nodes_map[N][N]; // map of closed (tried-out) nodes
static int open_nodes_map[N][N]; // map of open (not-yet-tried) nodes
static int dir_map[N][N]; // map of directions
vector<pair<int, int> > resDirection;

const int dir=8; // number of possible directions to go at any position
// if dir==8
static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<int, int>> pathFind( const int & xStart, const int & yStart,
                                 const int & xFinish, const int & yFinish );

class node
{
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority

public:
    node(int xp, int yp, int d, int p)
    {xPos=xp; yPos=yp; level=d; priority=p;}

    int getxPos() const {return xPos;}
    int getyPos() const {return yPos;}
    int getLevel() const {return level;}
    int getPriority() const {return priority;}

    void updatePriority(const int & xDest, const int & yDest)
    {
        priority=level+estimate(xDest, yDest)*10; //A*
    }

    // give better priority to going strait instead of diagonally
    void nextLevel(const int & i) // i: direction
    {
        level+=(dir==8?(i%2==0?10:14):10);
    }

    // Estimation function for the remaining distance to the goal.
    const int & estimate(const int & xDest, const int & yDest) const
    {
        static int xd, yd, d;
        xd=xDest-xPos;
        yd=yDest-yPos;

        // Euclidian Distance
        d=static_cast<int>(sqrt(xd*xd+yd*yd));

        // Manhattan distance
        //d=abs(xd)+abs(yd);

        // Chebyshev distance
        //d=max(abs(xd), abs(yd));

        return(d);
    }
};
void timer(int = 0)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);

    srand(time(NULL));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (rand() % 4 == 0)
                map[i][j] = WALL;
            else
                map[i][j] = 0;
        }
    for (int i = 0; i < N; ++i)
    {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][N - 1] = WALL;
        map[N - 1][i] = WALL;
    }
    map[heroCoordX][heroCoordY] = HERO;
    map[exitCoordX][exitCoordY] = EXIT;


    resDirection = pathFind(heroCoordX, heroCoordY, exitCoordX, exitCoordY);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            if(map[i][j] == WALL)
                continue;
            else
                map[i][j] = 0;
    }

    int nstep = 1;
    for (vector<pair<int, int> >::iterator k = resDirection.end() - 1; k != resDirection.begin() - 1; --k){

        int nx = k -> first;
        int ny = k -> second;
        map[nx][ny] = nstep;
        nstep++;
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j){
            if(open_nodes_map[i][j] == 1)
                map[i][j] = -10;
            else if (closed_nodes_map[i][j] == 1)
                map[i][j] = -20;

        }

    display();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if ((i == heroCoordX)&&(j == heroCoordY))
                glColor3f(0, 0, 1);
            else  if ((i == exitCoordX)&&(j == exitCoordY))
                glColor3f(1, 1, 0);
            else if (map[i][j] == WALL)
                glColor3f(0, 0, 0);
            else if (map[i][j] == 0)
                glColor3f(1, 1, 1);
            else if (map[i][j] == -10)
                glColor3f(0.58, 0.53, 0.53);
            else if (map[i][j] == -20)
                glColor3f(0.06, 0.96, 0.92);


            else
                glColor3f(map[i][j] / 48.0, 0, 0);

            glVertex2f((i) * 480 / N, (j) * 480 / N);
            glVertex2f((i + 1) * 480 / N, (j) * 480 / N);
            glVertex2f((i + 1) * 480 / N, (j + 1) * 480 / N);
            glVertex2f((i) * 480 / N, (j + 1) * 480 / N);
        }
    for (vector<pair<int, int> >::iterator i = resDirection.begin() + 1; i < resDirection.end(); ++i)
    {
        glColor3f(1, 0, 0);
        glVertex2f((i -> first) * 480 / N, (i -> second) * 480 / N);
        glVertex2f((i -> first + 1) * 480 / N, (i -> second) * 480 / N);
        glVertex2f((i -> first + 1) * 480 / N, (i -> second + 1) * 480 / N);
        glVertex2f((i -> first) * 480 / N, (i -> second + 1) * 480 / N);
    }
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(20, 1050 - 480 - 20);
    glutCreateWindow("Sample Algorithm");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, 480, 480, 0, -1, 1);
    glutDisplayFunc(display);
    timer();
    // glutTimerFunc(10, timer, 0);
    glutMainLoop();
}


vector<pair<int, int>> pathFind( const int & xStart, const int & yStart,
                                 const int & xFinish, const int & yFinish )
{
    // Создаем очередь с приоритеттом для хранения 2x свободных узлов
    static priority_queue<node> pq[2];
    static int pqi = 0; // pq index
    static node* n0;
    static node* m0;
    static int x, y, xdx, ydy;


    // Обуление карт с узлами
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            closed_nodes_map[i][j] = 0;
            open_nodes_map[i][j] = 0;
        }
    }

    // Создание начального узла и добавление его в очередь открытых узлов
    n0 = new node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pqi].push(*n0);
    open_nodes_map[N][N] = n0->getPriority(); // Пометить его на карте открытых узлов

    // A* поиск
    while(!pq[pqi].empty())
    {
        // Получить текущий узел с самым высоким приорритетом
        // из очереди с открытыми узлами
        n0 = new node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
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
            // Сгенерировать путь от финиша до старта
            // следуя направлению
            int j;
            vector<pair<int, int> > resDirection;
            while(x != xStart && y != yStart)
            {
                j = dir_map[x][y];
                resDirection.push_back(pair<int, int>(x, y));
                x += dx[j];
                y += dy[j];
            }
            // Удаление мусора
            delete n0;
            // Очистить оставшиеся узлы
            while(!pq[pqi].empty())
                pq[pqi].pop();
            return resDirection;
        }

        // Создание всех возможных направлений движения ( дочерних узлов )
        for(int i = 0; i < dir; i++)
        {
            xdx = x + dx[i]; ydy = y + dy[i];

            if(!(xdx < 0 || xdx > N-1 || ydy < 0 || ydy > N - 1 || map[xdx][ydy] == 1
                 || closed_nodes_map[xdx][ydy] == 1))
            {
                // Создание дочернего узла
                m0 = new node( xdx, ydy, n0->getLevel(), n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xFinish, yFinish);

                // Если он находится в открытом списке, тогда
                if(open_nodes_map[xdx][ydy] == 0)
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
                    //ОБновить направление родительского направления
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
bool operator<(const node & a, const node & b)
{
    return a.getPriority() > b.getPriority();
}
