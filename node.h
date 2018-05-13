#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <GL/glut.h>
#include <chrono>
#include <thread>
#include <math.h>
#include <queue>
#include <ctime> // содержит time()

class Node
{
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;

    // приоритет = уровень + оставшаяся оценка расстояния
    int priority;  // smaller: higher priority


public:
    Node(int xp, int yp, int d, int p);

    bool operator<(const Node & a);

    int getxPos() const;
    int getyPos() const;
    int getLevel() const;
    int getPriority() const;

    void updatePriority(const int & xDest, const int & yDest);
    // give better priority to going strait instead of diagonally
    void nextLevel(const int & i);

    // Функция оценки для оставшегося расстояния до цели.
    const int& estimate(const int & xDest, const int & yDest) const;
};

#endif // NODE_H
