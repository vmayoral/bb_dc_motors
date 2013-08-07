#!/usr/bin/env python
import rospy
from std_msgs.msg import String

import Adafruit_BBIO.PWM as PWM

# The DRV8837 needs two PWM signals to control a single motor so:
pin = "P9_42" 
pin2 = "P9_28"

def callback(data):
    #rospy.loginfo("\n");
    #rospy.loginfo(rospy.get_name() + ": I heard \n")
    #rospy.loginfo("%s\n" % data.data)
    #rospy.loginfo("\n");

    # process the data heard and call setDuty with the desired value
    if (len(data.data.split())) == 6:
        xvalue = data.data.split()[1] 
        setDuty(float(xvalue))

def setDuty(value):
    ##duty values are valid 0-100
    if value > 100:
        value = 100
    if value < 0:
        value = 0

    PWM.set_duty_cycle(pin, value)

def dcmotors():
    rospy.init_node('dc_motors', anonymous=True)
    rospy.Subscriber("imu_euler", String, callback)

    # init the PWM
    ##PWM.start(channel, duty, freq=2000)
    PWM.start(pin, 90)
    PWM.start(pin2, 100)

    rospy.spin()


if __name__ == '__main__':
    dcmotors()

