#!/bin/bash

SLOTS=/sys/devices/bone_capemgr.*/slots
echo am33xx_pwm     > $SLOTS
echo bone_pwm_P9_16 > $SLOTS 

echo "P9_16 now available under /sys/devices/ocp.2/pwm_test_P9_16.*"

