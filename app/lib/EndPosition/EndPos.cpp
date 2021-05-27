#include <Arduino.h>
#include "EndPos.h"

// initialize both inductive sensors
void EndPos::init_sensors(uint8_t pinUp, uint8_t pinDown)
{
    // set both sensors as Digital inputs
    pinMode(pinUp, INPUT);
    pinMode(pinDown, INPUT);
    this->pinUp=pinUp;
    this->pinDown=pinDown;
}
void EndPos::read_pins()
{
    // set the red values to the appropriate variables
    this->PosPhiUp = digitalRead(this->pinUp);
    this->PosPhiDown = digitalRead(this->pinDown);
}
// getter functions
int EndPos::getPosPhiUp()
{
    return this->PosPhiUp;
}
int EndPos::getPosPhiDown()
{
    return this->PosPhiDown;
}
//

// if desired you can Serial print the pin values
void EndPos::Serial_Print()
{
    Serial.print("the up sensor is: ");
    Serial.println(this->PosPhiUp);
    delay(600);
    Serial.print("the down sensor is: ");
    Serial.println(this->PosPhiDown);
    delay(600);
}
