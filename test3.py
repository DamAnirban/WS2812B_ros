#!/usr/bin/env python
import serial #Serial imported for Serial communication
import time 
import rospy
from geometry_msgs.msg import Twist
ArduinoSerial = serial.Serial('/dev/ttyACM0',9600)
time.sleep(2)
x = 1.0
y = -1.0

def callback(msg):
    rospy.loginfo("Received a /cmd_vel message!")
    rospy.loginfo("Linear Components: [%f, %f, %f]"%(msg.linear.x, msg.linear.y, msg.linear.z))
    rospy.loginfo("Angular Components: [%f, %f, %f]"%(msg.angular.x, msg.angular.y, msg.angular.z))

    var = float(msg.angular.z)
    print ("YOU ENTERED", var) 

    if (var > x): #if the value is 1
        ArduinoSerial.write('1') #send 1
        print ("CLOCKWISE")
        time.sleep(0.01)

    elif (var < y): #if the value is 0
        ArduinoSerial.write('0') #send 0
        print ("ANTICLOCK")
        time.sleep(0.01)

    else :
	ArduinoSerial.write('5') #send 5
        print ("Straight")
        time.sleep(0.01)

def listener():
    rospy.init_node('cmd_vel_listener')
    rospy.Subscriber("/cmd_vel", Twist, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
