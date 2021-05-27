#include <Wire.h>
#include <Arduino.h>
#include "RTClib.h"
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
void setup()
{
  Serial.begin(9600);
  // delay(2000);
  rtc.begin();
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); /* To manualy set date and time,    remove the coment // signs    and enter new values in the followingline   in this sequence: year, day, month, hour, minute and second.*/
  //rtc.adjust(DateTime(2020, 2, 24, 10, 00, 0));
}
void loop()
{
  DateTime now = rtc.now(); //Day of the weekSerial.print("Day of the week: ");
  if (now.hour() < 10)
  {
    Serial.print("0");
    Serial.print(now.hour());
  }
  else
  {
    Serial.print(now.hour(), DEC);
  }
  Serial.print(':');
  if (now.minute() < 10)
  {
    Serial.print("0");
    Serial.print(now.minute());
  }
  else
  {
    Serial.print(now.minute(), DEC);
  }
  Serial.print(':');
  if (now.second() < 10)
  {
    Serial.print("0");
    Serial.print(now.second());
  }
  else
  {
    Serial.print(now.second(), DEC);
  }
  Serial.println("");
}