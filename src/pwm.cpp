///  Simple C++ class wrapper for beaglebone PWM eHRPWM interface
//          Some of this code has been taken from https://github.com/clausqr/beaglebone-cpp-PWM

#include "pwm.h"
#include <stdexcept>
#include <fstream>
#include <sstream>

namespace cPWM {

/**
 * This class wraps the PWMss of the beaglebone,
 * but it accesses the PWMss by means of the sysfs interface,
 * so probably other systems are supported as well.
 * The sysfs filenames are defined in pwm.h.
 * The constructor just opens the sysfs files but doesn't write anything,
 * so in order to properly use the PWMss you need to follow all the steps
 * (frequency, period, polarity) before calling run.
 *
 * WARNING: PIN MUX AND CLOCK SETTINGS SHOULD BE DONE BEFORE USING THIS CLASS. 
 *
 * @param[pwm_name]	       name of the pins of the PWM (check /lib/firmware, e.g.: pwm_test_P9_16.10).
 * @return		a cPWM object
 *
 */
cPWM::cPWM(std::stringstream pwm_name)
{
	///TODO: 	Add clock selection (mmap). By now you must use setPWMReg.py method
	///FIXME:	pin mux settings should be done here? or at a highet level?
    
	cPWM::id = id;

    std::stringstream sysfsfile_duty_ns;
    std::stringstream sysfsfile_duty_percent;

    std::stringstream sysfsfile_period_ns;
    std::stringstream sysfsfile_period_freq;

	std::stringstream sysfsfile_polarity;
	std::stringstream sysfsfile_run;
    std::stringstream sysfsfile_request;

    sysfsfile_duty_ns << SYSFS_EHRPWM_PREFIX << "/" << pwm_name << "/" << SYSFS_EHRPWM_DUTY_NS;
    sysfsfile_duty_percent << SYSFS_EHRPWM_PREFIX << "/" << pwm_name << "/" << SYSFS_EHRPWM_DUTY_PERCENT;

    sysfsfile_period_ns << SYSFS_EHRPWM_PREFIX << "/" << pwm_name << "/" << SYSFS_EHRPWM_PERIOD_NS;
    sysfsfile_period_freq << SYSFS_EHRPWM_PREFIX << "/" << pwm_name << "/" << SYSFS_EHRPWM_PERIOD_FREQ;

	sysfsfile_polarity << SYSFS_EHRPWM_PREFIX << "/" << pwm_name << "/" << SYSFS_EHRPWM_POLARITY;
	sysfsfile_run << SYSFS_EHRPWM_PREFIX << "/" << pwm_name << "/" << SYSFS_EHRPWM_RUN;
	sysfsfile_request << SYSFS_EHRPWM_PREFIX << "/" << pwm_name << "/" << SYSFS_EHRPWM_REQUEST;

    // perform the initializations using the private variables
    sysfsfid_duty_ns.open(sysfsfile_duty_ns.str().c_str());
    sysfsfid_duty_percent.open(sysfsfile_duty_percent.str().c_str());

    sysfsfid_period_ns.open(sysfsfile_period_ns.str().c_str());
    sysfsfid_period_freq.open(sysfsfile_period_freq.str().c_str());

	sysfsfid_polarity.open(sysfsfile_polarity.str().c_str());
	sysfsfid_run.open(sysfsfile_run.str().c_str());

    sysfsfid_request.open(sysfsfile_request.str().c_str());
}

/**
 * Set the duty cycle for the PWMss
 *
 * @param[in]	nanoseconds:	duty cycle time in nanoseconds 
 *
 */
void cPWM::Duty_ns(unsigned int nanoseconds)
{
    if(nanoseconds > cPWM::period)
        throw std::out_of_range("Duty_ns: ");

    cPWM::duty = nanoseconds;
    sysfsfid_duty_ns << nanoseconds << std::endl;
}

/**
 * Set the duty cycle of the PWMss
 *
 * @param[in]	percent:	duty cycle time in percent 
 *
 */
void cPWM::Duty_percent(unsigned int percent)
{
    if(percent > 100)
        throw std::out_of_range("Duty_percent: ");

        sysfsfid_duty_percent << percent << std::endl;
}


/**
 * Set the period for the PWMss
 *
 * @param[in]	nanoseconds:	period time in nanoseconds
 *
 */
void cPWM::Period_ns(unsigned int nanoseconds)
{
        cPWM::period  = nanoseconds;
        cPWM::freq_Hz = 1000000000 / nanoseconds;
        sysfsfid_period_ns << nanoseconds << std::endl;
}

/**
 * Set the period for the PWMss
 *
 * @param[in]	freq_Hz:	PWM frequency in Hz
 *
 */
void cPWM::Period_freq(unsigned int freq_Hz)
{
        cPWM::freq_Hz = freq_Hz;
        cPWM::period  = 1000000000 / freq_Hz;
        sysfsfid_period_freq << freq_Hz<< std::endl;
}

/**
 * Set the polarity for the PWMss
 *
 * @param[in]	polarity  polarity
 *
 */
void cPWM::Polarity(Polarity polarity)
{
        switch (polarity)
        {
        case ActiveHigh:  sysfsfid_polarity << 1 << std::endl;
                          break;
        case ActiveLow:   sysfsfid_polarity << 0 << std::endl;
                          break;
        }
        cPWM::polarity = polarity;
}

/**
 * Set the PWM to run status
 *
 *
 */
void cPWM::Run()
{
	sysfsfid_run << "1" << std::endl;
	cPWM::run = 1;
}

/**
 * Stop the PWM
 *
 *
 */
void cPWM::Stop()
{
	sysfsfid_run << "0" << std::endl;
	cPWM::run = 0;
}


/**
 * cPWM Destructor, stops the PWMss
 *
 */
cPWM::~cPWM()
{
	sysfsfid_run << "0" << std::endl;

}

} /* namespace cPWM */
