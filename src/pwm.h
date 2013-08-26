///     Some of this code has been taken from https://github.com/clausqr/beaglebone-cpp-PWM

#ifndef CPWM_H_
#define CPWM_H_

#include <fstream>
#include <sstream>


#define CAPEMGR_SLOT "/sys/devices/bone_capemgr.7/slots"
#define SYSFS_EHRPWM_PREFIX "/sys/devices/ocp.2"
#define SYSFS_EHRPWM_DUTY_NS "duty"
#define SYSFS_EHRPWM_DUTY_PERCENT "duty_percent"
#define SYSFS_EHRPWM_PERIOD_NS "period_ns"
#define SYSFS_EHRPWM_PERIOD_FREQ "period_freq"
#define SYSFS_EHRPWM_POLARITY "polarity"
#define SYSFS_EHRPWM_RUN "run"
#define SYSFS_EHRPWM_REQUEST "request"

namespace cPWM {

    class cPWM {

        public:
            enum Polarity
            {
                ActiveHigh,
                ActiveLow
            };

        private:
            int id;
            int duty;
            int period;
            int freq_Hz;
            enum cPWM::Polarity polarity;
            int run;

            std::ofstream sysfsfid_duty_ns;
            std::ofstream sysfsfid_duty_percent;
            std::ofstream sysfsfid_period_ns;
            std::ofstream sysfsfid_period_freq;

            std::ofstream sysfsfid_polarity;
            std::ofstream sysfsfid_run;
            std::ofstream sysfsfid_request;

        public:

            cPWM(std::stringstream pwm_name);
            virtual ~cPWM();

            void Duty_ns(unsigned int nanoseconds);
            void Duty_percent(unsigned int percent);  //TODO: check if floats are possible

            void Period_ns(unsigned int nanoseconds);
            void Period_freq(unsigned int freq_Hz);

            void Polarity(cPWM::Polarity polarity);
            void Run();
            void Stop();
    };

} /* namespace cPWM */
#endif /* CPWM_H_ */
