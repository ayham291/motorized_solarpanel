#include <Arduino.h>
#include <MoveMotors.h>
#include <Wifi.h>
#include <FindSun.h>

int check_rotation = 1;
int ticks = 0;

Find_Sun FindSun;
Wireless client;

void setup()
{
  Serial.begin(9600);
  FindSun.init_compass();
  client.Wifi_setup();
}

void loop()
{
  ticks++;
  check_rotation = FindSun.check_rotation();
  if (check_rotation == 0)
    FindSun.check_tilt();
  if(ticks==5)
  {
    client.send_Data();
    ticks=0;
  }
  client.gen_Status();
}
