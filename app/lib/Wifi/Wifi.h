#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <EndPos.h>
#include <MoveMotors.h>
#include <SunPosition.h>
#include <RTClib.h>
#include <Wire.h>
#include <FindSun.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <PCF8591.h>

class Wireless
{
private:
    WiFiClientSecure client;
    RTC_DS3231 rtc_temp_only;
    EndPos endPos;
    Motor turnTable;
    Motor tiltPanel;
    SonnenStand sunpos;
    Find_Sun FindSun;

public:
    void Wifi_setup();
    void send_Data();
    int status = WL_IDLE_STATUS;
    int check_rotation = 1;

    String postData;
    String endpos_val;

    int ticks = 0;
    int gen_status = 1;
    int az;
    float diode;
    int offset;
    float temperature;
};

#endif // WIFI_H