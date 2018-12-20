#include "ClockController.h"

//default pins for display
#define displayCLK 10
#define displayDIO 11

SevenSegmentExtended display(displayCLK, displayDIO);


#define maxAlarms 2

//array with alarms.
alarm alarmsTab[maxAlarms] = {
    //{hour, minute, second}, on (turned on) , used (working now), pin
    {{7, 0, 0}, true, false, 4},
    {{7, 0, 0}, true, false, 4}
};



ClockController::ClockController(){
    clock.begin();
    display.begin();
    display.setBacklight(100);
}

void ClockController::interuptEachSecond(){
    clock.setEachSecondInteruption();
};

uint8_t ClockController::getHour(){
    return clock.getHour();
};

uint8_t ClockController::getMinute(){
    return clock.getMinute();
};
uint8_t ClockController::getSecond(){
    return clock.getSecond();
};

void ClockController::showTime(){
    time = clock.getTimeShort();
    display.printTime(time.hour, time.minute, false);
    display.setColonOn(!display.getColonOn());
};

void ClockController::showDate();

void ClockController::showTemperature(){
    clock.forceTemperatureConversion();
    float temp = clock.readTemperature();
    // display.printTime(temp/1, (temp*100), false);
    // display.setColonOn(false);
    
};

void ClockController::showHour(){
    rawText = "T " + ((char)time.hour/10+'0') + ((char)time.hour%10+'0');
    display.printRaw(rawText);
};

void ClockController::showMinute(){
    rawText = "M " + ((char)time.minute/10+'0') + ((char)time.minute%10+'0');
    display.printRaw(rawText);
};

void ClockController::showSecond(){
    rawText = "S " + ((char)time.second/10+'0') + ((char)time.second%10+'0');
    display.printRaw(rawText);
};

void ClockController::incrementHour(){
    uint8_t temp = clock.getTimeShort().hour;
    (temp < 23) ? temp++ : temp = 0;
    clock.setHour(temp);
};

void ClockController::incrementMinute(){
    uint8_t temp = clock.getTimeShort().minute;
    (temp < 59) ? temp++ : temp = 0;
    clock.setMinute(temp);
};
void ClockController::incrementSecond(){
     uint8_t temp = clock.getTimeShort().second;
    (temp < 59) ? temp++ : temp = 0;
    clock.setSecond(temp);
};

void ClockController::decrementHour(){
    uint8_t temp = clock.getTimeShort().hour;
    (temp > 0) ? temp-- : temp = 23;
    clock.setHour(temp);
};
void ClockController::decrementMinute(){
    uint8_t temp = clock.getTimeShort().minute;
    (temp > 0) ? temp-- : temp = 59;
    clock.setMinute(temp);
};
void ClockController::decrementSecond(){
    uint8_t temp = clock.getTimeShort().second;
    (temp > 0) ? temp-- : temp = 59;
    clock.setSecond(temp);
};

void ClockController::incrementAlarmHour(uint8_t id){
    (alarmsTab[id].t.hour < 23) ? alarmsTab[id].t.hour++ : alarmsTab[id].t.hour = 0;   
};

void ClockController::incrementAlarmMinute(uint8_t id){
    (alarmsTab[id].t.minute < 59) ? alarmsTab[id].t.minute++ : alarmsTab[id].t.minute = 0;   
};

void ClockController::incrementAlarmSecond(uint8_t id){
    (alarmsTab[id].t.second < 59) ? alarmsTab[id].t.second++ : alarmsTab[id].t.second = 0;   
};

void ClockController::decrementAlarmHour(uint8_t id){
    (alarmsTab[id].t.hour > 0) ? alarmsTab[id].t.hour-- : alarmsTab[id].t.hour = 23;   
};

void ClockController::decrementAlarmMinute(uint8_t id){
    (alarmsTab[id].t.minute > 0) ? alarmsTab[id].t.minute-- : alarmsTab[id].t.minute = 59;   
};

void ClockController::decrementAlarmSecond(uint8_t id){
    (alarmsTab[id].t.second > 0) ? alarmsTab[id].t.second-- : alarmsTab[id].t.second = 59;   
};

void ClockController::switchAlarm(uint8_t id){
    alarmsTab[id].on = !alarmsTab[id].on;
};

void checkAlarms();
void resetAlarms();