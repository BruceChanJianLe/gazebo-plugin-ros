#ifndef ROS_PUBLISHER_PLUGIN_H_
#define ROS_PUBLISHER_PLUGIN_H_

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
    class ros_publisher_plugin : public WorldPlugin
    {
        private:
            /// @brief ROS publisher node handle
            std::shared_ptr<ros::NodeHandle> publisher_nh_;

            /// @brief ROS publisher node
            ros::Publisher pub_;

            /// @brief ROS callback Queue
            ros::CallbackQueue pub_callback_queue_;

            /// @brief Pointer to thread
            std::shared_ptr<std::thread> thread_ptr_;

            /// @brief publisher msg
            std_msgs::Int32 msg_;

        public:
            /// @brief Constructor
            ros_publisher_plugin();

            /// @brief Destructor
            ~ros_publisher_plugin();

            /// @brief Overload Load() from WorldPlugin, this function should not block the process
            virtual void Load(
                physics::WorldPtr _world,
                sdf::ElementPtr _sdf
            ) override;
    };

} // namespace gazebo

#endif