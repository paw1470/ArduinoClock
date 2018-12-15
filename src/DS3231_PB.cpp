#include "DS3231_PB.h"

uint8_t DS3231_PB::getSecond(void){
    uint8_t value;
    value = readRegister8(DS3231_REG_TIME_SEC);
    value = bcd2dec(value);
    return value;
}

uint8_t DS3231_PB::getMinute(void){
    uint8_t value;
    value = readRegister8(DS3231_REG_TIME_MIN);
    value = bcd2dec(value);
    return value;
}

uint8_t DS3231_PB::getHour(void){
    uint8_t value;
    value = readRegister8(DS3231_REG_TIME_HOUR);
    value = bcd2dec(value);
    return value;
}

uint8_t DS3231_PB::getDay(void){
    uint8_t value;
    value = readRegister8(DS3231_REG_TIME_DAY);
    value = bcd2dec(value);
    return value;
}

uint8_t DS3231_PB::getDate(void){
    uint8_t value;
    value = readRegister8(DS3231_REG_TIME_DATE);
    value = bcd2dec(value);
    return value;
}

uint8_t DS3231_PB::getMonth(void){
    uint8_t value;
    value = readRegister8(DS3231_REG_TIME_MONTH);
    value = bcd2dec(value);
    return value;
}

uint8_t DS3231_PB::getYear(void){
    uint8_t value;
    value = readRegister8(DS3231_REG_TIME_YEAR);
    value = bcd2dec(value);
    return value + 20000;
}

void DS3231_PB::setSecond(uint8_t second){
    writeRegister8(DS3231_REG_TIME_SEC, dec2bcd(second));
}

void DS3231_PB::setMinute(uint8_t minute){
    writeRegister8(DS3231_REG_TIME_MIN, dec2bcd(minute));
}

void DS3231_PB::setHour(uint8_t hour){
    writeRegister8(DS3231_REG_TIME_HOUR, dec2bcd(hour));
}

void DS3231_PB::setDay(uint8_t day){
    //day should be counted 
    //writeRegister8(DS3231_REG_TIME_DAY, dec2bcd(day));
}

void DS3231_PB::setDate(uint8_t date){
    //should change day
    //writeRegister8(DS3231_REG_TIME_DATE, dec2bcd(date));
}

void DS3231_PB::setMonth(uint8_t month){
    //shoudl change day
    //writeRegister8(DS3231_REG_TIME_MONTH, dec2bcd(month));
}

void DS3231_PB::setYear(uint8_t year){
    //should change day
    //writeRegister8(DS3231_REG_TIME_YEAR, dec2bcd(year));
}


void DS3231_PB::setEachSecondInteruption(void){
    setSquareWaveFreq(DS3231_1HZ);
}


RTCTimeHMS DS3231_PB::getTimeShort(void){
    int values[3];

    Wire.beginTransmission(DS3231_ADDRESS);
    #if ARDUINO >= 100
        Wire.write(DS3231_REG_TIME);
    #else
        Wire.send(DS3231_REG_TIME);
    #endif
    Wire.endTransmission();

    Wire.requestFrom(DS3231_ADDRESS, 3);

    while(!Wire.available()) {};

    for (int i = 2; i >= 0; i--)
    {
        #if ARDUINO >= 100
            values[i] = bcd2dec(Wire.read());
        #else
            values[i] = bcd2dec(Wire.receive());
        #endif
    }

    Wire.endTransmission();

    tShort.hour = values[4];
    tShort.minute = values[5];
    tShort.second = values[6];
}

//dont like orginal names
void DS3231_PB::setSquareWaveFreq(DS3231_sqw_t freq){
    setOutput(freq);
}

void DS3231_PB::enableSqareWaveOutput(bool enabled){
    enableOutput(enabled);
}

bool DS3231_PB::isSqareWaveOutput(void){
    return isOutput();
}
DS3231_sqw_t DS3231_PB::getSquareWaveFreq(){
    return getOutput();
}

void DS3231_PB::forceTemperatureConversion(void){
    forceConversion();
}