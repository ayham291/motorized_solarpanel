#ifndef __SONNEN_
#define __SONNEN_

#include <RTClib.h>

class SonnenStand {
private:
    RTC_DS3231 rtc;
    DateTime time;
public:
    int get_arr_pos();
    float get_azimuth(int arr_pos);

};

#endif