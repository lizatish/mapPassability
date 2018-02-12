#include <iostream>
#include <iomanip>
#include <vector>
#include <GL/glut.h>
#include <chrono>
#include <thread>
using namespace std::this_thread;     // sleep_for, sleep_until
using std::chrono::system_clock;
using namespace std::chrono; // nanoseconds, system_clock, seconds


using namespace std;
void display();
const int N = 100;
const int WALL = 55;
const int HERO = -5;
const int EXIT = -8;
int map[N][N];
vector<pair<int, int> > wave;

void timer(int = 0)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);

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
    map[N / 8 + 5][N / 4] = HERO;
    map[N - 10][N / 2] = EXIT;


    vector<pair<int, int> > oldWave;
    oldWave.push_back(pair<int, int>(N / 8 + 5, N / 4));
    int nstep = 1;
    map[N / 8 + 5][N / 4] = nstep;
    const int dx[] = { 0, 1, 0, -1 };
    const int dy[] = { -1, 0, 1, 0 };

    bool isExitFind = false;
    while (!isExitFind)
    {
        ++nstep;
        wave.clear();
        for (vector<pair<int, int> >::iterator i = oldWave.begin(); i != oldWave.end(); ++i){
            for (int d = 0; d < 4; ++d){
                int nx = i -> first + dx[d];
                int ny = i -> second + dy[d];

                if(map[nx][ny] == EXIT){
                    map[nx][ny] = nstep;
                    display();

                    wave.erase(wave.end() - d, wave.end());
                    wave.push_back(pair<int, int>(nx, ny));

                    isExitFind = true;
                    break;
                }
                else if (map[nx][ny] == 0){
                    wave.push_back(pair<int, int>(nx, ny));
                    map[nx][ny] = nstep;
                    display();

                    if (nx == N - 2 && ny == N - 2){
                        isExitFind = true;
                        break;
                    }
                }
            }
            if(isExitFind)
                break;
        }
        oldWave = wave;

    }

    sleep_for(nanoseconds(700000000));
    int x = N - 10;
    int y = N / 2;
    wave.clear();
    wave.push_back(pair<int, int>(x, y));
    while (map[x][y] != 1)
    {
        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (map[x][y] - 1 == map[nx][ny])
            {
                x = nx;
                y = ny;
                wave.push_back(pair<int, int>(x, y));
                break;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            if(map[i][j] == WALL)
                continue;
            else
                map[i][j] = 0;
    }

    nstep = 1;
    for (vector<pair<int, int> >::iterator k = wave.end() - 1; k != wave.begin() - 1; --k){

        int nx = k -> first;
        int ny = k -> second;
        map[nx][ny] = nstep;
        nstep++;
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
            if (map[i][j] == WALL)
                glColor3f(1, 1, 1);
            else if (map[i][j] == -1)
                glColor3f(0, 0, 0);
            else
                glColor3f(map[i][j] / 48.0, 0, 0);
            glVertex2f((i) * 480 / N, (j) * 480 / N);
            glVertex2f((i + 1) * 480 / N, (j) * 480 / N);
            glVertex2f((i + 1) * 480 / N, (j + 1) * 480 / N);
            glVertex2f((i) * 480 / N, (j + 1) * 480 / N);
        }
    for (vector<pair<int, int> >::iterator i = wave.begin(); i != wave.end(); ++i)
    {
        glColor3f(0, 1, 0);
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
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
}

