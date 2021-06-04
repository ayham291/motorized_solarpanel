#include "FindSun.h"
#include <PCF8591.h>

PCF8591 AD_Converter(0x48);

// init the sensor
void Find_Sun::init_compass()
{
    compass.setReset();
    compass.init();
    endPos.init_sensors(D6, D5);
    compass.setMode(Mode_Continuous, ODR_10Hz, RNG_8G, OSR_512);
    SunPos.init_time();
    pinMode(A0, INPUT);
    tiltpanel.init_motor(D7, D4, 2);
    turnTable.init_motor(D0, D3, 1);
    AD_Converter.begin();
}
// gets the azimuth value of the sensor
int Find_Sun::get_current_azimuth()
{
    compass.read();
    this->current_azimuth = compass.getAzimuth();
    return current_azimuth;
}
void Find_Sun::start_pos()
{
    endPos.read_pins();
    tiltpanel.switch_pwr(OFF);
    turnTable.switch_pwr(OFF);
    while (endPos.getPosPhiDown() == 1)
    {
        endPos.read_pins();
        tiltpanel.rotate(DOWN);
        // Serial.println("A");
        delay(10);
    }
    tiltpanel.switch_pwr(OFF);
    while (get_current_azimuth() != 0)
    {
        turnTable.rotate(LEFT);
        get_current_azimuth();
        // Serial.println("X");
        delay(10);
    }
    turnTable.switch_pwr(OFF);
    delay(500);
}
// calc the offset to sun then sent to the motors
int Find_Sun::offset_to_Sun()
{
    Sun_at_azimuth = SunPos.get_azimuth(SunPos.get_arr_pos());
    offset = current_azimuth - Sun_at_azimuth;
    return offset;
}
//
void Find_Sun::check_tilt()
{
    endPos.read_pins();
    ldr0 = AD_Converter.analogRead(AIN0);
    ldr1 = AD_Converter.analogRead(AIN1);
    offset_adc = ldr1 - ldr0;
    int time_var = SunPos.get_arr_pos();
    if (time_var >= 19 && time_var <= 41) // time betwee 9:30 and 15:00 -> Adustable time
    {
            if (endPos.getPosPhiUp() == 0 && offset_adc >= 10)
            {
                tiltpanel.switch_pwr(OFF);
                tiltpanel.rotate(UP);
            }
            else if (endPos.getPosPhiDown() == 1 && offset_adc <= -10)
            {
                tiltpanel.switch_pwr(OFF);
                tiltpanel.rotate(DOWN);
            }

            else if (offset_adc < 10 || offset_adc > -10)
                tiltpanel.switch_pwr(OFF);
    }

    else // Time before and after adustable time -> Tilt goto Max
    {
        if (endPos.getPosPhiUp() == 1)
        {
            tiltpanel.switch_pwr(OFF);
        }
        else
        {
            tiltpanel.switch_pwr(OFF);
            tiltpanel.rotate(UP);
        }
    }
}

int Find_Sun::check_rotation()
{
    SunPos.get_azimuth(SunPos.get_arr_pos()); //update target angle
    get_current_azimuth();                    //update current angle

    if (offset_to_Sun() < -TOLERANCE) //Angle is not ok
    {
        turnTable.rotate(RIGHT);
        return 1;
    }
    else if (offset_to_Sun() > TOLERANCE) //Angle is not ok
    {
        turnTable.rotate(LEFT);
        return 1;
    }

    else if (offset_to_Sun() >= TOLERANCE || offset_to_Sun() >= -TOLERANCE) //Angle is ok
    {
        turnTable.switch_pwr(OFF);
        return 0;
    }
    return 1;
}
int Find_Sun::get_ldr0()
{
    ldr0 = AD_Converter.analogRead(AIN0);
    return ldr0;
}
int Find_Sun::get_ldr1()
{
    ldr1 = AD_Converter.analogRead(AIN1);
    return ldr1;
}
