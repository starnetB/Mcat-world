#include <pluginlib/class_loader.hpp>
#include <nav_core/base_local_planner.h>


int main(int argc,char** argv)
{
    // 创建一个ClassLoader，用来加载plugin
    pluginlib::ClassLoader<nav_core::BaseLocalPlanner> bb("robot_setup_tf","nav_core::BaseLocalPlanner");
    try
    {
        boost::shared_ptr<nav_core::BaseLocalPlanner> mybase=bb.createInstance("local_planner/LocalPlanner");
        std::string name="llee";
        tf2_ros::Buffer* tf;
        costmap_2d::Costmap2DROS* costmap_ros;
        mybase->initialize(name,tf,costmap_ros);
        mybase->isGoalReached();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}