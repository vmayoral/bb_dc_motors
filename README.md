ros_bb_dc_motors
==================

ROS package that launches a node to control a DC motor connected to the BeagleBone. The dc motors are controlled using the 
[Adafruit's BeagleBone IO Python Library](https://github.com/adafruit/adafruit-beaglebone-io-python.git).

##Install the Adafruit's BB IO Python Library in the BeagleBone (using Angstrom)
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



