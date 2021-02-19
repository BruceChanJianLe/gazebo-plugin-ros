#ifndef CONNECT_WORLD_UPDATE_PLUGIN_H_
#define CONNECT_WORLD_UPDATE_PLUGIN_H_

// Gazebo plugin features
#include <gazebo/common/Plugin.hh>
#include <gazebo/common/common.hh>

// ROS features
#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <std_msgs/Int32.h>

// Others
#include <thread>
#include <memory>

namespace gazebo
{
    class connect_world_update : public WorldPlugin
    {
        private:
            /// @brief Pointer to the update event connection
            event::ConnectionPtr updateConnection_;

            /// @brief Counter
            unsigned long long int count_;

        public:
            /// @brief Constructor
            connect_world_update();

            /// @brief Destructor
            ~connect_world_update();

            /// @brief Overload Load() from WorldPlugin, this function should not block the process
            virtual void Load(
                physics::WorldPtr _world,
                sdf::ElementPtr _sdf
            ) override;
    };

} // namespace gazebo

#endif