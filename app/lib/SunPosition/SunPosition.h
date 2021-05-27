#ifndef __SONNEN_
#define __SONNEN_

#include <RTClib.h>

class SonnenStand {
private:
    RTC_DS3231 rtc;
    DateTime time;
public:
    void init_time();
    int get_arr_pos();
    int get_azimuth(int arr_pos);

};

#endif