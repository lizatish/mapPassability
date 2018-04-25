#ifndef ROSNODE_H
#define ROSNODE_H

#include <QThread>
#include <iostream>
#include <unistd.h>

#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>

using namespace std;

class RosNode : public QObject
{
    Q_OBJECT
private:

    // Сообщение с картой
    nav_msgs::OccupancyGrid mapMessage;
    // Сообщение с путем
    nav_msgs::Path pathMessage;

    // Точка для загрузки в сообщение пути
    geometry_msgs::PoseStamped point;

    // Процесс разрешен
    bool isAllowProcess;

    // Хранение только что пришедших пути и карты
    vector<int> mapToLoad;
    vector<pair<int, int>> pathToLoad;

public:
    RosNode();
public slots:
    void process();
    void setMap(vector<int> om);
    void setPath(vector<pair<int, int>> path);

};
#endif // ROSNODE_H
