#include <Arduino.h>
#include <EndPos.h>
#include <MoveMotors.h>
#include <SunPosition.h>
#include <RTClib.h>
#include <Wire.h>
#include <FindSun.h>

EndPos endPos;
Motor turnTable;
Motor tiltPanel;
SonnenStand sunpos;
Find_Sun FindSun;
void setup()
{
  Serial.begin(9600);
  endPos.init_sensors(D6, D5);
  turnTable.init_motor(D0, D3, 1);
  tiltPanel.init_motor(D7, D4, 2);
  sunpos.init_time();
  FindSun.init_compass();
  pinMode(A0, INPUT);
}

void loop()
{
  FindSun.get_current_azimuth();
  sunpos.get_azimuth(sunpos.get_arr_pos());
  if(FindSun.offest_to_sun()<-2)
    turnTable.rotate(RIGHT);
  else if(FindSun.offest_to_sun()>2)
    turnTable.rotate(LEFT);
  else if (FindSun.offest_to_sun()>=2 || FindSun.offest_to_sun()>=-2)
    turnTable.switch_pwr(OFF);
  // Serial.print("KOMPASS WERT: ");
  // Serial.println(FindSun.get_current_azimuth());
  // delay(1000);

  // Serial.print("SOllWERT: ");
  // Serial.println(sunpos.get_azimuth(sunpos.get_arr_pos()));
  // delay(1000);

  // Serial.print("OFFSET: ");
  // Serial.println(FindSun.offest_to_sun());
  // delay(1000);

  
  Serial.println(analogRead(A0));


  // endPos.read_pins();
  // if (endPos.getPosPhiUp() == 1 && endPos.getPosPhiDown() == 1)
  // {
  //   tiltPanel.switch_pwr(OFF);
  //   tiltPanel.rotate(DOWN); // auch on
  // }
  // else if (endPos.getPosPhiDown() == 0 && endPos.getPosPhiUp() == 0)
  // {
  //   tiltPanel.switch_pwr(OFF);
  //   tiltPanel.rotate(UP);
  // }
  // else
  // {
  //   tiltPanel.switch_pwr(OFF);
  // }
  // Serial.println(sunpos.get_azimuth(sunpos.get_arr_pos()));
}