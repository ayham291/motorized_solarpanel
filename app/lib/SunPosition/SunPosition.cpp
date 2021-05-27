#include <SunPosition.h>

const float azimuth[] = // 5:00 -> 6:00 -> 15min step
    {
        62, 65, 67.50, 71, 74,
        // 6:15
        76, 78, 82, 85,
        // 7:15
        88, 91, 94, 96,
        // 8:15
        100, 103, 106, 110,
        // 9:15
        114, 118, 122, 127,
        // 10:15
        133, 137, 143, 149,
        // 11:15
        155, 161, 169, 177,
        // 12:15
        183, 190, 196, 203,
        // 13:15
        210, 216, 221, 227,
        // 14:15
        232, 236, 242, 245,
        // 15:15
        249, 253, 256, 259,
        // 16:15
        263, 266, 269, 272,
        // 17:15
        275, 277, 280, 283,
        // 18:15
        286, 289, 291, 294,
        // 19:15
        296, 300, 303, 305
        // 20:15
};

void SonnenStand::init_time()
{
    this->rtc.begin();
    this->time = rtc.now();
}

// calc index -> get azimuth of the claced time
int SonnenStand::get_arr_pos()
{
    int hr = this->time.hour();
    int min = this->time.minute();
    min = min / 15;
    hr = ((hr - 5) * 4) + 1;
    return hr + min;
}

// return the azimuth value of the current time (now azimuth)
int SonnenStand::get_azimuth(int arr_pos)
{
    // check if it's after 20:00 or before 05:00
    arr_pos = arr_pos * (time.hour() > 5) * (time.hour() < 20) + 0 * (time.hour() > 20);
    return azimuth[arr_pos];
}