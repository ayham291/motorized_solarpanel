#include <FindSun.h>

// init the sensor
void Find_Sun::init_compass()
{
    compass.setReset();
    compass.init();
    compass.setMode(Mode_Continuous, ODR_10Hz, RNG_8G, OSR_512);
    SunPos.init_time();
}
// gets the azimuth value of the sensor
int Find_Sun::get_current_azimuth()
{
    compass.read();
    this->current_azimuth = compass.getAzimuth();
    return current_azimuth;
}

// TO BE TESTED WITH NEGATIVE OFFSETS!!!
int Find_Sun::offest_to_sun()
{
    Sun_at_azimuth = SunPos.get_azimuth(SunPos.get_arr_pos());
    offset = current_azimuth - Sun_at_azimuth;
    return offset;
}
//
int Find_Sun::if_offset()
{
    if (offset > 2 || 2 > offset)
        return 1;
    return 0;
}