///     Some of this code has been taken from https://github.com/clausqr/beaglebone-cpp-PWM

#ifndef CPWM_H_
#define CPWM_H_

#include <fstream>


#define CAPEMGR_SLOT "/sys/devices/bone_capemgr.7/slots"
#define SYSFS_EHRPWM_PREFIX "/sys/devices/ocp.2/pwm_test_P9_16.10"
#define SYSFS_EHRPWM_SUFFIX_A ":0"
#define SYSFS_EHRPWM_SUFFIX_B ":1"
#define SYSFS_EHRPWM_DUTY_NS "duty_ns"
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
            int dutyA;
            int dutyB;
            int period;
            int freq_Hz;
            enum cPWM::Polarity polarityA;
            enum cPWM::Polarity polarityB;
            int runA;
            int runB;

            std::ofstream sysfsfid_dutyA_ns;
            std::ofstream sysfsfid_dutyA_percent;
            std::ofstream sysfsfid_dutyB_ns;
            std::ofstream sysfsfid_dutyB_percent;
            std::ofstream sysfsfid_period_ns;
            std::ofstream sysfsfid_period_freq;
            std::ofstream sysfsfid_polarityA;
            std::ofstream sysfsfid_runA;
            std::ofstream sysfsfid_requestA;
            std::ofstream sysfsfid_polarityB;
            std::ofstream sysfsfid_runB;
            std::ofstream sysfsfid_requestB;

        public:

            cPWM(int id);
            virtual ~cPWM();

            void DutyA_ns(unsigned int nanoseconds);
            void DutyA_percent(unsigned int percent);  //TODO: check if floats are possible

            void DutyB_ns(unsigned int nanoseconds);
            void DutyB_percent(unsigned int percent); //TODO: check if floats are possible

            void Period_ns(unsigned int nanoseconds);
            void Period_freq(unsigned int freq_Hz);

            void PolarityA(cPWM::Polarity polarity);
            void RunA();
            void StopA();
            void PolarityB(cPWM::Polarity polarity);
            void RunB();
            void StopB();
    };

} /* namespace cPWM */
#endif /* CPWM_H_ */
