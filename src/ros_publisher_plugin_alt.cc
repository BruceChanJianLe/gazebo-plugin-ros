#include "gazebo-plugin-ros/ros_publisher_plugin_alt.hh"

GZ_REGISTER_WORLD_PLUGIN(gazebo::ros_publisher_plugin_alt);

namespace gazebo
{
    ros_publisher_plugin_alt::ros_publisher_plugin_alt()
    {
    }

    ros_publisher_plugin_alt::~ros_publisher_plugin_alt()
    {
        // Disable callback queue
        pub_callback_queue_.clear();
        pub_callback_queue_.disable();

        // Shutdown ROS node handle when class is destroy
        publisher_nh_->shutdown();

        // Wait for thread to join
        if(thread_ptr_->joinable())
            thread_ptr_->join();
    }

    void ros_publisher_plugin_alt::Load(
        physics::WorldPtr _world,
        sdf::ElementPtr _sdf
    )
    {
        // Ensure that ROS node for Gazebo has been initialized
        if(!ros::isInitialized())
        {
            int argc = 0; char ** argv = NULL;
            ros::init(argc, argv, "gazebo_ros_publisher_node", ros::init_options::NoSigintHandler);
        }

        // Initiate ROS node handle
        publisher_nh_ = std::make_shared<ros::NodeHandle> ();

        /** Initiate publisher with a custom callback queue
         *  Initializing in multi-threading manner
         */
        {
            publisher_nh_->setCallbackQueue(& pub_callback_queue_);
            pub_ = publisher_nh_->advertise<std_msgs::Int32>("publisher_status", 1);
        }

        // Initiate publisher msg
        msg_.data = 0;

        // Spin off child thread for publisher
        this->thread_ptr_ = std::make_shared<std::thread> (
            [this]()
            {
                // Set a process rate
                ros::Rate r(1);
                while (this->publisher_nh_->ok())
                {
                    // Reset msg data to 0
                    if(this->msg_.data > 100)
                        this->msg_.data = 0;

                    // Publish data
                    this->pub_.publish(msg_);
                    ++msg_.data;

                    // Process callback queue
                    this->pub_callback_queue_.callAvailable(ros::WallDuration(0.0));

                    // Sleep
                    r.sleep();
                }
            }
        );

        // Succesful message for user
        gzmsg << ros::this_node::getName() << " successfully started ros_publisher_plugin_alt plugin." << std::endl;
    }

} // namespace gazebo
