#ifndef QUALISYS_ODOM_H
#define QUALISYS_ODOM_H

#include <ros/ros.h>
#include <ros/node_handle.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/Pose.h>

#include <qualisys/KalmanFilter.h>
//#include <qualisys/Subject.h>
#include <qualisys/Subject.h>

namespace qualisys
{
class QualisysOdom
{
 public:
  QualisysOdom(ros::NodeHandle &nh);
  bool init();
  //void QualisysCallback(const qualisys::Subject::ConstPtr &qualisys_msg);
  void QualisysCallback(const qualisys::Subject::ConstPtr &qualisys_msg);

 private:
  QualisysOdom(const QualisysOdom& );
  QualisysOdom& operator=(const QualisysOdom& );

  void PublishTransform(const geometry_msgs::Pose &pose,
                        const std_msgs::Header &header,
                        const std::string &child_frame_id);

  ros::NodeHandle nh;
  qualisys::KalmanFilter kf_;
  ros::Publisher odom_pub_;
  std::string child_frame_id_;
  tf2_ros::TransformBroadcaster tf_broadcaster_;
  bool publish_tf_;
  ros::Subscriber qualisys_sub_;
};

} // qualisys

#endif // QUALISYS_ODOM_H
