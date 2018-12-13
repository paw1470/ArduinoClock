#ifndef DS3231_PB_h
#define DS3231_PB_h

#include "DS3231.h"

#define DS3231_REG_TIME_SEC         (0x00)
#define DS3231_REG_TIME_MIN         (0x01)
#define DS3231_REG_TIME_HOUR        (0x02)
#define DS3231_REG_TIME_DAY         (0x03)
#define DS3231_REG_TIME_DATE        (0x04)
#define DS3231_REG_TIME_MONTH       (0x05)
#define DS3231_REG_TIME_YEAR        (0x06)

struct RTCTime
{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};

class DS3231_PB : public DS3231{

    
}