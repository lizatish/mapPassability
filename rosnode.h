#ifndef ROSNODE_H
#define ROSNODE_H

#include <QThread>
#include <iostream>
#include <unistd.h>

#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
using namespace std;

class RosNode : public QObject
{
    Q_OBJECT
private:
    bool is_enable;
    float linear_speed;
    float angular_speed;
    bool is_set_speed;
    nav_msgs::OccupancyGrid message;
    bool isAllowProcess;

    vector<int> map;

public:
    RosNode();
public slots:
    void process();
    void setMap(vector<int> om);
};
#endif // ROSNODE_H
