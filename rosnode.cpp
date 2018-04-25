
#include "rosnode.h"

RosNode::RosNode()
{
    isAllowProcess = true;

}

void RosNode::process() {

    // Инициализация ROS
    int argc;
    char* argv[100];
    ros::init(argc, argv, "mapPassability_qt");

    // Создание публикатора пути
    ros::NodeHandle p;
    ros::Publisher path_pub =
            p.advertise<nav_msgs::Path>("/path", 8);

    // Создание публикатора карты
    ros::NodeHandle m;
    ros::Publisher map_pub =
            m.advertise<nav_msgs::OccupancyGrid>("/mapPassability", 2);

    // Инициализация fixed frame
    pathMessage.header.frame_id = "map";
    pathMessage.header.stamp = ros::Time::now();

    ros::spinOnce();
    ros::Rate rate = 10;

    while(isAllowProcess && ros::ok()) {
        cout<<"Thread running"<<endl;

        // Инициализация параметров карты
        mapMessage.info.height = 20;
        mapMessage.info.width = 20;
        mapMessage.info.resolution = 1;
        mapMessage.info.origin.position.x = -10;
        mapMessage.info.origin.position.y = -10;
        mapMessage.data.resize((mapMessage.info.height * mapMessage.info.width)/mapMessage.info.resolution);

        // Формирование пути
        for (uint i = 0; i < pathToLoad.size(); i++){
            point.pose.position.x = pathToLoad[i].second - 10;
            point.pose.position.y = pathToLoad[i].first - 10;
            point.pose.position.z = 0.0;
            point.pose.orientation.x = 0.0;
            point.pose.orientation.y = 0.0;
            point.pose.orientation.z = 0.0;
            point.pose.orientation.w = 1.0;
            pathMessage.poses.push_back(point);
        }

        // Формирование карты
        for(uint i = 0; i < mapToLoad.size(); i++)
            mapMessage.data[i] = mapToLoad[i];

        // Отправка сообщений
        map_pub.publish(mapMessage);
        path_pub.publish(pathMessage);

        ros::spinOnce();
        rate.sleep();
    }
}


void RosNode::setMap(vector<int> om){
    mapToLoad = om;
}
void RosNode::setPath(vector<pair<int, int> > path){
    pathToLoad = path;
    cout << pathToLoad.size() << endl;

}
