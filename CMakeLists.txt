cmake_minimum_required(VERSION 2.8.3)
project(qualisys)

#find_package(Boost REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  geometry_msgs
  tf
)

add_message_files(DIRECTORY msg)
generate_messages(DEPENDENCIES geometry_msgs)

catkin_package(
  #  INCLUDE_DIRS include
  #  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS message_runtime
  )

include_directories(
  include
  ${catkin_INCLUDE_DIRS})
link_directories(
  ${catkin_LIBRARY_DIRS})

add_definitions("-std=c++0x -Wall")

add_executable(qualisys_node src/Qualisys2Ros.cpp
  include/NBC_Markup.cpp
  include/Network.cpp
  include/RTPacket.cpp
  include/RTProtocol.cpp)
target_link_libraries(qualisys_node
  ${catkin_LIBRARIES}
  )
