cmake_minimum_required(VERSION 3.0.2)
project(gazebo-plugin-ros)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roscpp
  rospy
  std_msgs
)

find_package(gazebo REQUIRED)

link_directories(${GAZEBO_LIBRARY_DIRS})

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES gazebo-plugin-ros
#  CATKIN_DEPENDS gazebo_ros roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIR}
  ${GAZEBO_INCLUDE_DIRS}
)

add_library(helloRosWorld SHARED src/hello_ros_world.cc)
target_link_libraries(helloRosWorld ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_library(rosPublisherPlugin SHARED src/ros_publisher_plugin.cc)
target_link_libraries(rosPublisherPlugin ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_library(rosPublisherPluginAlt SHARED src/ros_publisher_plugin_alt.cc)
target_link_libraries(rosPublisherPluginAlt ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})