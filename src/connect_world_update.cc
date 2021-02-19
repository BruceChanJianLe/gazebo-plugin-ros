#include "gazebo-plugin-ros/connect_world_update.hh"

GZ_REGISTER_WORLD_PLUGIN(gazebo::connect_world_update);

namespace gazebo
{
    connect_world_update::connect_world_update()
    :   count_(0)
    {
    }

    connect_world_update::~connect_world_update()
    {
    }

    void connect_world_update::Load(
        physics::WorldPtr _world,
        sdf::ElementPtr _sdf
    )
    {
        // Ensure that ROS node for Gazebo has been initialized
        if(!ros::isInitialized())
        {
            int argc = 0; char ** argv = NULL;
            ros::init(argc, argv, "connect_world_update_node", ros::init_options::NoSigintHandler);
        }


        // Connect to Update Loop
        this->updateConnection_ = event::Events::ConnectWorldUpdateBegin(
            [this](...) -> void
            {
                /** Do something here, but note that this loop is 10000 Hz
                 *  Hence, you may want to spin another thread instead of using this update loop.
                 */
                ROS_INFO_STREAM(ros::this_node::getName() << " doing something " << this->count_);
                ++this->count_;
            }
        );

        // Succesful message for user
        gzmsg << ros::this_node::getName() << " successfully started connect_world_update plugin." << std::endl;
    }

} // namespace gazebo
