#include <Arduino.h>
#include <EndPos.h>
#include <MoveMotors.h>
#include <SunPosition.h>
#include <RTClib.h>
#include <Wifi.h>
#include <Wire.h>
#include <FindSun.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <PCF8591.h>

int check_rotation = 1;

int ticks = 0;
int gen_status = 1;

Find_Sun FindSun;
Wireless client;

void setup()
{
  Serial.begin(9600);
  client.Wifi_setup();
  FindSun.start_pos();
}

void loop()
{
  check_rotation = FindSun.check_rotation();

  if (check_rotation == 0)
    FindSun.check_tilt();

  client.send_Data();
  
  gen_status = 0;
}
