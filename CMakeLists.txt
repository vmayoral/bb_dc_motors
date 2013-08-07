cmake_minimum_required(VERSION 2.8.3)
project(ros_bb_dc_motors)

find_package(catkin REQUIRED COMPONENTS rospy std_msgs)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_bb_dc_motors
  CATKIN_DEPENDS rospy std_msgs
#  DEPENDS system_lib
)

include_directories(include
    ${catkin_INCLUDE_DIRS}
)

install(PROGRAMS scripts/dc-motors.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

