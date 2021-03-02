# Gazebo Plugin ROS

This repository demonstrates the procedures to setup and use a Gazebo ROS plugin.

## Types of Gazebo Plugins

There are several types of Gazebo plugins `world`, `model`, `sensor`, `visual`. Please note that different plugins should be loaded differently, if not it will failed.

Below are some links to clarify the ways to load the different types of plugins.

http://gazebosim.org/tutorials?tut=ros_gzplugins  
https://answers.gazebosim.org//question/4702/gazebo-19-libgazebo_ros_openni_kinectso-incorrect-plugin-type/  

The `ModelPlugin` is inserted in the URDF inside the `<robot>` element. It is wrapped with the `<gazebo>` pill, to indicate information passed to Gazebo. For example:
```xml
<robot>
  ... robot description ...
  <gazebo>
    <plugin name="differential_drive_controller" filename="libdiffdrive_plugin.so">
      ... plugin parameters ...
    </plugin>
  </gazebo>
  ... robot description ...
</robot>
```

Likewise,

## Obtaining Arguement from sdf

For more information please refer to [Gazebo Plugin Example](https://bitbucket.org/theconstructcore/tc_gazebo_custom_plugins/src/master/).

## Gazebo Plugin Export (for other packages to find the plugin)

https://answers.ros.org/question/360991/gazebo-does-not-launch-when-entering-the-launch-command-2020/  
https://answers.gazebosim.org//question/15200/cant-load-plugin-with-roslaunch/  
https://github.com/osrf/servicesim/blob/follow_plugin/servicesim_competition/launch/competition.launch  
http://wiki.ros.org/roslaunch/XML/env  
http://wiki.ros.org/roslaunch/XML  
http://gazebosim.org/tutorials?tut=ros_roslaunch  
http://gazebosim.org/tutorials?tut=components&cat=get_started  
http://gazebosim.org/tutorials?tut=plugins_model&cat=write_plugin  

## Error

```bash
error: no matching function for call to ‘gazebo::event::EventT<void(const gazebo::common::UpdateInfo&)>::Connect(gazebo::ros_publisher_plugin::Load(gazebo::physics::WorldPtr, sdf::ElementPtr)::<lambda()>&)’
               { return worldUpdateBegin.Connect(_subscriber); }
                                                            ^
In file included from /usr/include/gazebo-9/gazebo/common/SystemPaths.hh:36:0,
                 from /usr/include/gazebo-9/gazebo/common/Plugin.hh:37,
                 from /home/chanjl/temp_ws/src/gazebo-plugin-ros/include/gazebo-plugin-ros/ros_publisher_plugin.hh:5,
                 from /home/chanjl/temp_ws/src/gazebo-plugin-ros/src/ros_publisher_plugin.cc:1:
/usr/include/gazebo-9/gazebo/common/Event.hh:558:19: note: candidate: gazebo::event::ConnectionPtr gazebo::event::EventT<T>::Connect(const std::function<T>&) [with T = void(const gazebo::common::UpdateInfo&); gazebo::event::ConnectionPtr = boost::shared_ptr<gazebo::event::Connection>]
     ConnectionPtr EventT<T>::Connect(const std::function<T> &_subscriber)
                   ^~~~~~~~~
```

For this error, you can either put `const gazebo::common::UpdateInfo&` inside of your lambda function, please read the error carefully. If you do not intend to use the arguement, you can just swallow it by using the `...` method, which swallow any arguement.

## Reference
- Gazebo Plugin [youtube_link_part_1](https://www.youtube.com/watch?v=LRjT_1huVKY&feature=emb_logo) [youtube_link_part_2](https://www.youtube.com/watch?v=kLJt5U7wrGQ)
- Gazebo Plugin Example [link_bitbucket](https://bitbucket.org/theconstructcore/tc_gazebo_custom_plugins/src/master/)
- Gazebo Plugin Velodyne Example [link_bitbucket](https://bitbucket.org/DataspeedInc/velodyne_simulator/src/master/)
- Gazebo Tutorial [link_website](http://gazebosim.org/tutorials?tut=ros_plugins)
- Gazebo ROS Answer [link_ros_answer](https://answers.ros.org/question/287068/how-to-write-a-custom-gazebo-plugin-for-ros/)