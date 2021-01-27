#include "gazebo-plugin-ros/hello_ros_world.hh"


GZ_REGISTER_WORLD_PLUGIN(gazebo::hello_ros_world)
namespace gazebo
{
    hello_ros_world::hello_ros_world()
    {
        ;
    }


    hello_ros_world::~hello_ros_world()
    {
        ;
    }


    void hello_ros_world::Load(
        physics::WorldPtr _world,
        sdf::ElementPtr _sdf
    )
    {
        // Ensure that ROS node for Gazebo has been initialized
        if(!ros::isInitialized())
        {
            ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
                << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package");
            return;
        }

        ROS_INFO_STREAM("Hello ROS World!");
    }
} // namespace gazebo
