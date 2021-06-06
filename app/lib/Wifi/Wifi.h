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
// #include <WiFiClient.h>
#include <PCF8591.h>

class Wireless
{
private:
    WiFiClient client;
    RTC_DS3231 rtc_temp_only;
    DateTime time;
    EndPos endPos;
    Motor turnTable;
    Motor tiltPanel;
    SonnenStand sunpos;
    Find_Sun FindSun;
    int status = WL_IDLE_STATUS;

public:
    void Wifi_setup();
    void send_Data();
    int gen_Status();
    String postData;
    String endpos_val;
    int ticks = 0;
    int gen_status = 1;
    int az;
    int offset;
    float temperature;
};

#endif // WIFI_H