/*
 * Copyright 2015 Kartik Mohta
 * Author: Kartik Mohta <kartikmohta@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <ros/ros.h>
#include <qualisys/QualisysDriver.h>

int main(int argc, char *argv[]) {

  ros::init(argc, argv, "qualisys");
  ros::NodeHandle nh("~");

  qualisys::QualisysDriver qualisys_driver(nh);
  if(!qualisys_driver.init()) {
    ROS_INFO("Initialization of the qualisys driver failed!");
    return -1;
  }

  while(ros::ok())
  {
    qualisys_driver.run();
    ros::spinOnce();
  }

  ROS_INFO("Shutting down");
  qualisys_driver.disconnect();

  return 0;
}
