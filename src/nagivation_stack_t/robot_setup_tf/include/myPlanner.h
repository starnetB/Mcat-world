#ifndef MY_PLANNER_H_
#define MY_PLANNER_H_

#include <nav_core/base_local_planner.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>


using namespace std;


//创建规划插件
namespace local_planner{

    class LocalPlanner:public nav_core::BaseLocalPlanner
    {
        public:
            LocalPlanner();
        
            LocalPlanner(std::string name,
                         tf2_ros::Buffer* tf,
                         costmap_2d::Costmap2DROS* costmap_ros);
            
            ~LocalPlanner();
            
            void initialize(std::string name, 
                            tf2_ros::Buffer* tf,
                            costmap_2d::Costmap2DROS* costmap_ros);

            bool setPlan(const std::vector<geometry_msgs::PoseStamped>& orig_global_plan);

            bool computeVelocityCommands(geometry_msgs::Twist& cmd_vel);

            bool isGoalReached();
        private:
            tf2_ros::Buffer* tf_;
            costmap_2d::Costmap2DROS* costmap_ros_;
            bool initialized_;
    };
}
#endif