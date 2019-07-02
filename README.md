# WS2812B_ros
ROS node for individually addressable RGB LED strip WS2812B. Used in cart direction indication by subscribing to /cmd_vel

## Requirement
1. Arduino - FastLED lib
2. ROS - PySerial

## Setup
1. Upload light.ino to controller (separate from the motor controller)
2. Run - rosrun package-name light_ros.py
3. Make sure port dev/ttyACM0 is correctly mentioned in light_ros.py

