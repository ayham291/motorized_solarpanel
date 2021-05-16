#include <Arduino.h>
#include <RTClib.h>
#include <SunPosition.h>

const float azimuth[] = // 5:00 -> 6:00 -> 15min step
    {
        62.00, 65.00, 67.50, 71.00, 74.00,
        // 6:15
        76.00, 78.00, 82.00, 85.00,
        // 7:15
        88.00, 91.00, 94.00, 96.00,
        // 8:15
        100.00, 103.00, 106.00, 110.00,
        // 9:15
        114.00, 118.00, 122.00, 127.00,
        // 10:15
        133.00, 137.00, 143.00, 149.00,
        // 11:15
        155.00, 161.00, 169.00, 177.00,
        // 12:15
        183.00, 190.00, 196.00, 203.00,
        // 13:15
        210.00, 216.00, 221.00, 227.00,
        // 14:15
        232.00, 236.00, 242.00, 245.00,
        // 15:15
        249.00, 253.00, 256.00, 259.00,
        // 16:15
        263.00, 266.00, 269.00, 272.00,
        // 17:15
        275.00, 277.00, 280.00, 283.00,
        // 18:15
        286.00, 289.00, 291.00, 294.00,
        // 19:15
        296.00, 300.00, 303.00, 305.00
        // 20:15
};

// calc index -> get azimuth of the claced time
int SonnenStand::get_arr_pos()
{
    rtc.begin();
    time = rtc.now();
    int hr = time.hour();
    int min = time.minute();
    min = min / 15;
    hr = ((hr - 5) * 4) + 1;
    return hr + min;
}

// return the azimuth value of the current time (now azimuth)
float SonnenStand::get_azimuth(int arr_pos)
{
    // check if it's after 20:00 or before 05:00
    arr_pos = arr_pos * (time.hour() > 5) * (time.hour() < 20) + 0 * (time.hour() > 20);
    return azimuth[arr_pos];
}