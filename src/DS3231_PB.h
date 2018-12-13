#ifndef DS3231_PB_h
#define DS3231_PB_h

#include "DS3231.h"
#include <Wire.h>

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define DS3231_REG_TIME_SEC         (0x00)
#define DS3231_REG_TIME_MIN         (0x01)
#define DS3231_REG_TIME_HOUR        (0x02)
#define DS3231_REG_TIME_DAY         (0x03)
#define DS3231_REG_TIME_DATE        (0x04)
#define DS3231_REG_TIME_MONTH       (0x05)
#define DS3231_REG_TIME_YEAR        (0x06)

struct RTCTimeShort
{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};

class DS3231_PB : public DS3231{
    public:      
        uint8_t getSecond(void);
        uint8_t getMinute(void);
        uint8_t getHour(void);
        uint8_t getDay(void);
        uint8_t getDate(void);
        uint8_t getMonth(void);
        uint8_t getYear(void);
      
        void setSecond(uint8_t second);
        void setMinute(uint8_t minute);
        void setHour(uint8_t hour);
        void setDay(uint8_t day);
        void setDate(uint8_t date);
        void setMonth(uint8_t month);
        void setYear(uint8_t year);

        void setEachSecondInteruption(void);

        RTCTimeShort getTimeShort(void);

        //dont like orginal names
        void setSquareWaveFreq(DS3231_sqw_t freq);
        void enableSqareWaveOutput(bool enabled);
        bool isSqareWaveOutput(void); 
        DS3231_sqw_t getSquareWaveFreq(void);
        void forceTemperatureConversion(void);

        private:
        RTCTimeShort tShort;
};
#endif 