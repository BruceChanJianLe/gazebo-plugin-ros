#ifndef HELLO_ROS_WORLD_H_
#define HELLO_ROS_WORLD_H_

// Gazebo plugin features
#include <gazebo/common/Plugin.hh>

// ROS basic features
#include <ros/ros.h>


namespace gazebo
{
    /** 
     * @class hello_ros_world class 
     * @brief This class is merely an example to writing a gazebo plugin
     */
    class hello_ros_world : public WorldPlugin
    {
        public:
            /// @brief Constructor
            hello_ros_world();

            /// @brief Destructor
            ~hello_ros_world();

            /// @brief Overload Load() from WorldPlugin
            virtual void Load(
                physics::WorldPtr _world,
                sdf::ElementPtr _sdf
            )   override;
    };
} // namespace gazebo

#endif