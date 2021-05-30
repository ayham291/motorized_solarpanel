#include <FindSun.h>

#define PEAKVALUE 350

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
}
// gets the azimuth value of the sensor
int Find_Sun::get_current_azimuth()
{
    compass.read();
    this->current_azimuth = compass.getAzimuth();
    return current_azimuth;
}

// calc the offset to sun then sent to the motors
int Find_Sun::offest_to_sun()
{
    Sun_at_azimuth = SunPos.get_azimuth(SunPos.get_arr_pos());
    offset = current_azimuth - Sun_at_azimuth;
    return offset;
}
//
void Find_Sun::check_tilt()
{
    endPos.read_pins();
    int light_intens;
    light_intens = analogRead(A0);
    int time_var = SunPos.get_arr_pos();
    if (time_var >= 19 && time_var <= 41)
    {
        if (light_intens > PEAKVALUE)
        {
            if (endPos.getPosPhiUp() == 1 && endPos.getPosPhiDown() == 1)
            {
                tiltpanel.switch_pwr(OFF);
                tiltpanel.rotate(DOWN);

                while (endPos.getPosPhiDown() == 1 && light_intens > PEAKVALUE)
                {
                    endPos.read_pins();
                    light_intens = analogRead(A0);
                    delay(10);
                }
            }
            else if (endPos.getPosPhiUp() == 0 && endPos.getPosPhiDown() == 0)
            {
                tiltpanel.switch_pwr(OFF);
                tiltpanel.rotate(UP);
                while (endPos.getPosPhiUp() == 0 && light_intens > PEAKVALUE)
                {
                    endPos.read_pins();
                    light_intens = analogRead(A0);
                    delay(10);
                }
            }
            else if (endPos.getPosPhiUp() == 0 && endPos.getPosPhiDown() == 1)
            {
                if (time_var >= 34)
                {
                    tiltpanel.switch_pwr(OFF);
                    tiltpanel.rotate(UP);
                }
                else
                {
                    tiltpanel.switch_pwr(OFF);
                    tiltpanel.rotate(DOWN);
                }
            }
        }
        else
        {
            tiltpanel.switch_pwr(OFF);
        }
    }
    else
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