#include <Arduino.h>
#include <TM1637Display.h>
#include "DS3231.h"
#include "LowPower.h"

#define CLK 10
#define DIO 11

TM1637Display display(CLK, DIO);

DS3231 clock;
RTCTime t;
int clockInteruptPin = 2;
int setButtonPin = 3;
byte screenDots = 0b01000000;
bool settingClock = false;

struct alarm{
    int startTime;
    int endTime;
    int controlPin;
    int outputPin;
};
 
alarm alarms[4] = {
    {700, 800, A3, 7},
    {730, 800, A2, 6},
    {800, 805, A1, 5},
    {810, 811, A0, 4}
};

void alarmController(int time){
    for(int i=0; i<4; i++){
        if(digitalRead(alarms[i].controlPin)==LOW){
            if(alarms[i].startTime <= time && time < alarms[i].endTime){
                digitalWrite(alarms[i].outputPin, HIGH);
            }else{
                digitalWrite(alarms[i].outputPin, LOW);
            }
        }else{        
            digitalWrite(alarms[i].outputPin, LOW);
        }
    }
}

void screenShowTime(){
    screenDots ^=0b01000000;
    t = clock.getTime();
    int time = (t.hour * 100) + t.minute;
    display.showNumberDecEx(time, screenDots, true, 4, 0);
    alarmController(time);
}

void wake(){ 
}

void wakeForSetting(){ 
    settingClock = true;
}

void setup() {
    clock.begin();
    clock.enable32kHz(false);
    clock.setOutput(DS3231_1HZ);
    // clock.enableOutput(true);
    display.setBrightness(0x0A);
    pinMode(clockInteruptPin,INPUT_PULLUP);
    pinMode(setButtonPin, INPUT_PULLUP);
    for(int i = 0; i<4; i++){
        pinMode(alarms[i].controlPin, INPUT_PULLUP);
        pinMode(alarms[i].outputPin, OUTPUT);
    }
    attachInterrupt(digitalPinToInterrupt(clockInteruptPin), wake, FALLING);
    attachInterrupt(digitalPinToInterrupt(setButtonPin), wakeForSetting, FALLING);
}


void settingMode(){
    detachInterrupt(setButtonPin);


}



void loop() {
    if(settingClock){

    } else{
        LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
        screenShowTime();
    }
}