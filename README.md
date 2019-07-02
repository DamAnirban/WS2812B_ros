# WS2812B_ros
ROS node for individually addressable RGB LED strip WS2812B. Used in cart direction indication by subscribing to /cmd_vel

##Requirement
Arduino - FastLED lib
ROS - PySerial

##Setup
1. Upload light.ino to controller (separate from the motor controller)
2. Run - rosrun package-name light_ros.py
