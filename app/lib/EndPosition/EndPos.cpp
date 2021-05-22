#include <Arduino.h>
#include "EndPos.h"

// initialize both inductive sensors
void EndPos::init_sensors(uint8_t pinUp, uint8_t pinDown)
{
    // set both sensors as Digital output
    pinMode(pinUp, OUTPUT);
    pinMode(pinDown, OUTPUT);
    // set the red values to the appropriate variables
    this->PosPhiUp = digitalRead(pinUp);
    this->PosPhiDown = digitalRead(pinDown);
}
// getter functions
int EndPos::getPosPhiUp()
{
    return PosPhiUp;
}
int EndPos::getPosPhiDown()
{
    return PosPhiDown;
}
//

// if desired you can Serial print the pin values
void EndPos::Serial_Print()
{
    Serial.print("the up sensor is: ");
    Serial.println(PosPhiUp);
    Serial.print("the down sensor is: ");
    Serial.println(PosPhiDown);
}
