#ifndef __FINDSUN_
#define __FINDSUN_

#include <Arduino.h>
#include <SunPosition.h>
#include <QMC5883LCompass.h>
#include <math.h>


#define Mode_Standby 0b00000000
#define Mode_Continuous 0b00000001
// Output data rate
#define ODR_10Hz 0b00000000
#define ODR_50Hz 0b00000100
#define ODR_100Hz 0b00001000
#define ODR_200Hz 0b00001100
// Measure range
#define RNG_2G 0b00000000
#define RNG_8G 0b00010000
// Over sampling rate
#define OSR_512 0b00000000
#define OSR_256 0b01000000
#define OSR_128 0b10000000
#define OSR_64 0b11000000



class Find_Sun
{
private:
    QMC5883LCompass compass;
    SonnenStand SunPos;
    float current_azimuth;
    float offset;
public:
    void init_compass();
    float get_current_azimuth();
    float offest_to_sun();
    int if_offset();
};

#endif