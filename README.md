bb_dc_motors
==================

ROS package that launches a node to control a DC motor connected to the BeagleBone.

<img src="https://raw.github.com/vmayoral/beagle-ros/master/docs/images/bb_dc_motors_bb.png" width="500px" />

Examples are provided both in python and C++: 
* The python file [dc-motors.py](https://github.com/vmayoral/bb_dc_motors/blob/master/scripts/dc-motors.py) launches a ROS node that reads from the topic **imu_euler** and controls the velocity of the motors with the x value of the **imu_euler** readings. The python code uses the 
[Adafruit's BeagleBone IO Python Library](https://github.com/adafruit/adafruit-beaglebone-io-python.git).

* [pwm.h](https://github.com/vmayoral/bb_dc_motors/blob/master/src/pwm.h) and [pwm.cpp](https://github.com/vmayoral/bb_dc_motors/blob/master/src/pwm.cpp) provide a C++ class that wraps the PWM sysfs interface of the Beaglebone (kernel 3.8). Using this code might probably lead to support in other systems. A [script](https://github.com/vmayoral/bb_dc_motors/tree/master/scripts/config_P9_16.sh) has been created to configure the sysfs. This [example](https://github.com/vmayoral/bb_dc_motors/tree/master/src/example_P9_16.cpp) illustrates how to use the cPWM C++ class coded.

-----

####HOW-TO Install the Adafruit's BB IO Python Library in the BeagleBone (using Angstrom)
There's a conflict with python-nose that conflicts with the *Easiest* method of installation so if you want to get it in the BeagleBone and you are using Angstrom use the following instructions (the Manual method provided):

```Shell
git clone git://github.com/adafruit/adafruit-beaglebone-io-python.git
#set the date and time
/usr/bin/ntpdate -b -s -u pool.ntp.org
#install dependency
opkg update && opkg install python-distutils
cd adafruit-beaglebone-io-python
python setup.py install
```
-----


####[dc_motors](https://github.com/vmayoral/bb_dc_motors/blob/master/scripts/dc-motors.py)
ROS node that reads the IMU values and modulates the motor speed using PWM according to the x-axis values of the IMU. It uses Beaglebone's EHRPWM pins P9_42 and P9_28.

#####Subscribed topics
*imu_euler (std_msgs:String)*
