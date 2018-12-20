#ifndef ClockController_h
#define ClockController_h

#include "SevenSegmentExtended.h"
#include "DS3231_PB.h"
#include "LowPower.h"


struct alarm{
    RTCTimeHMS t;
    bool on;
    bool used;
    uint8_t pin;
};


class ClockController{
    public:
        ClockController();
        void interuptEachSecond();

        void showTime();
        void showDate();
        void showTemperature();

        void showHour();
        void showMinute();
        void showSecond();

        uint8_t getHour();
        uint8_t getMinute();
        uint8_t getSecond();

        void incrementHour();
        void incrementMinute();
        void incrementSecond();
        void decrementHour();
        void decrementMinute();
        void decrementSecond();

        void incrementAlarmHour(uint8_t id);
        void incrementAlarmMinute(uint8_t id);
        void incrementAlarmSecond(uint8_t id);
        void decrementAlarmHour(uint8_t id);
        void decrementAlarmMinute(uint8_t id);
        void decrementAlarmSecond(uint8_t id);
        void switchAlarm(uint8_t id);

        void checkAlarms();
        void resetAlarms();

        
    private:
        RTCTimeHMS time;
        uint8_t *rawText = new uint8_t[4]; 
        uint8_t lastAlarmDate;
        DS3231_PB clock;
};
#endif