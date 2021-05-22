#include "endpos.h"
#include "Arduino.h"

// initialize both inductive sensors
void EndPos::init_sensors(uint8_t pinUp, uint8_t pinDown)
{
    // set both sensors as Digital output
    pinMode(pinUp, OUTPUT);
    pinMode(pinDown, OUTPUT);
    // set the red values to the appropriate variables
    this.PosPhiUP = digitalRead(pinUp);
    this.PosPhiDown = digitalRead(pinDown);
}
// getter functions
int EndPos::getPosPhiUp()
{
    return PosPhiUP;
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
    Serial.println(PosPhiUP);
    Serial.print("the down sensor is: ");
    Serial.println(PosPhiDown);
}
