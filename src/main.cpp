#include <Arduino.h>
#include <TM1637Display.h>
#include "DS3231_PB.h"
#include "LowPower.h"

#define CLK 10
#define DIO 11

TM1637Display display(CLK, DIO);

DS3231_PB clock;

void setup() {
   
}


void loop() {

}