#ifndef ASTARSEARCH_H
#define ASTARSEARCH_H

#include "node.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <GL/glut.h>
#include <chrono>
#include <thread>
#include <math.h>
#include <queue>
#include <ctime> // содержит time()

using namespace std;
class AStarSearch
{
private:
    const int N = 20;
    int** closed_nodes_map; // map of closed (tried-out) nodes
    int** open_nodes_map; // map of open (not-yet-tried) nodes
    int** dir_map; // map of directions

    const int dir = 8;
    int* dx;
    int* dy;

    // Создаем очередь с приоритеттом для хранения 2x свободных узлов
    priority_queue<Node> pq[2];
    int pqi = 0; // pq index
    Node* n0;
    Node* m0;
    int y;
    int x;
    int xdx, ydy;
    vector<pair<int, int> > resDir;

    int startX;
    int startY;


public:
    AStarSearch();

    vector<pair<int, int>> checkOnEnd();
    vector<pair<int, int>> pathFind( const int & xStart, const int & yStart,
                                     const int & xFinish, const int & yFinish, int** myMap );


};

#endif // ASTARSEARCH_H
