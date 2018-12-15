#include "ClockController.h"

//default pins for screen
#define screenCLK 10;
#define screenDIO 11;

//array with alarms.
alarm AlarmsTab[4] = {
    //{hour, minute, second}, on, used, pin
    {{7, 0, 0}, true, false, 4},
    {{7, 0, 0}, true, false, 4},
    {{7, 0, 0}, true, false, 4},
    {{7, 0, 0}, true, false, 4}
};



ClockController::ClockController(){
    clock.begin();
}