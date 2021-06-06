#include <Arduino.h>
#include <MoveMotors.h>
#include <Wifi.h>
#include <FindSun.h>

int check_rotation = 1;
int ticks = 0;
Find_Sun FindSun;
Wireless client;
Motor turnTable;
Motor tiltPanel;

void setup()
{
  Serial.begin(9600);
  turnTable.init_motor(D0, D3, 1);
  tiltPanel.init_motor(D7, D4, 2);
  FindSun.init_compass();
  client.Wifi_setup();
  // FindSun.start_pos();
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
