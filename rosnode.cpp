#include "rosnode.h"

RosNode::RosNode()
{
    isAllowProcess = true;

}

void RosNode::process() {
    int argc;
    char* argv[100];
    ros::init(argc, argv, "mapPassability_qt");
    //Узел ROS
    ros::NodeHandle n;
    //Publisher
    ros::Publisher velocity_pub =
            n.advertise<nav_msgs::OccupancyGrid>("/mapPassability", 2);

    ros::Rate rate = 10;
    while(isAllowProcess && ros::ok()) {
        cout<<"Thread running"<<endl;

        message.info.height = 20;
        message.info.width = 20;
        message.info.resolution = 1;


        std::vector<signed char> a;

        for(int i = 0; i < map.size(); i++)
            a.push_back(map[i]);

        message.data = a;


        velocity_pub.publish(message);
        ros::spinOnce();
        rate.sleep();
    }
}
void RosNode::setMap(vector<int> om){
    map = om;
}
