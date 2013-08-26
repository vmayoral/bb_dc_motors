///  Example implementation of the Simple C++ class wrapper for beaglebone PWM eHRPWM interface

#include "pwm.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	cout << "Hello Beagle!" << endl;

    // assuming that the clock and the pinmux is already done
	cPWM::cPWM* a;
    a = new cPWM::cPWM("pwm_test_P9_16.10");

	a->Period(20000000);
	a->Duty(  1000000);
	a->Polarity(1);
	a->Run();
	usleep(100000);	//pausa de 0.1s=100,000us
	a->DutyA( 1500000);
	a->Stop();
	return 0;
}

