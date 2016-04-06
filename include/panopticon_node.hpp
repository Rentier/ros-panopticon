#pragma once

#include <string>

#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf/transform_broadcaster.h>

namespace rmr {
class PanopticonNode {
 public:
  PanopticonNode(ros::NodeHandle _nh);
  ~PanopticonNode();

  void waitForWorldFrame(const std::string& topic);
  void spinOnce();

 private:
  ros::NodeHandle nh;

  ros::Subscriber subCam4;
  ros::Subscriber subCam5;

  tf::TransformBroadcaster br;

  geometry_msgs::TransformStamped origin;

  void cameraCallback(const geometry_msgs::TransformStamped::ConstPtr& msg);
};
}