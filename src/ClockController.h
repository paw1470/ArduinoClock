#ifndef ClockController_h
#define ClockController_h

#include <TM1637Display.h>
#include "DS3231_PB.h"
#include "LowPower.h"


class ClockController{
    public:
        // ClockController(uint8_t displayCLK, uint8_t displayDIO, );
        
    private:
        TM1637Display display;
        DS3231_PB clock;
};
#endif