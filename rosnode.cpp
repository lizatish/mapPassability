#include "rosnode.h"

RosNode::RosNode()
{
    isAllowProcess = true;

}

void RosNode::process() {
    int argc;
    char* argv[100];
    ros::init(argc, argv, "turtle_control_qt");
    //Узел ROS
    ros::NodeHandle n;
    //Publisher
    ros::Publisher velocity_pub =
            n.advertise<nav_msgs::OccupancyGrid>("/turtle1/cmd_vel", 2);

    ros::Rate rate = 10;
    while(isAllowProcess && ros::ok()) {
        cout<<"Thread running"<<endl;


        message.info.height = map.size() / 4;
        message.info.width = map.size() / 4;
        message.info.resolution = 1;


        std::vector<signed char> a;

        for(int i = 0; i < map.size(); i++)
            a.push_back(map[i]);

        //        int p[] = {100, 100, 50, 0,  100, 50,
        //                   0, 0, 50, 50, 50, 50,
        //                   0, 0, 0, 0, 50, 100,
        //                   0, 0, 50, 50, 50, 50,
        //                   0, 0, 50, 50, 50, 50,
        //                   0, 0, 50, 50, 50, 50, };

        //        std::vector<signed char> a;
        //        for(int i = 0; i < 36; i++){
        //            a.push_back(p[i]);


        //        std::vector<signed char> a(p, p+16);
        message.data = a;


        velocity_pub.publish(message);
        ros::spinOnce();
        rate.sleep();
        //        isAllowProcess = false;
    }
}
void RosNode::setMap(vector<int> om){
    map = om;
    isAllowProcess = true;
}