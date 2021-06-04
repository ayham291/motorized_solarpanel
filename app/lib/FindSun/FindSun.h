#ifndef __FINDSUN_
#define __FINDSUN_

#include <Arduino.h>
#include <SunPosition.h>
#include <QMC5883LCompass.h>
#include <SunPosition.h>
#include <MoveMotors.h>
#include <EndPos.h>
#include <PCF8591.h>


#define TOLERANCE 3

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
    int Sun_at_azimuth;
    int current_azimuth;
    int offset;
    int offset_adc;
    int ldr0;
    int ldr1;
    Motor tiltpanel;
    Motor turnTable;
    EndPos endPos;
  
public:
    void init_compass();
    int get_current_azimuth();
    int offset_to_Sun();
    void check_tilt();
    int check_rotation();
    void start_pos();
    int get_ldr0();
    int get_ldr1();
};

#endif
