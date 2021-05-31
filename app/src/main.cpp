#include <Arduino.h>
#include <EndPos.h>
#include <MoveMotors.h>
#include <SunPosition.h>
#include <RTClib.h>
#include <Wire.h>
#include <FindSun.h>
#include <ESP8266WiFi.h>

char ssid[] = "ard";
char pass[] = "maxardayham";
int status = WL_IDLE_STATUS;
int check_rotation=1;
char server[] = "192.168.8.102";
String postData_k;
String postData_d;
String postData;

WiFiClient client;

int az;

float diode;
int offset;
EndPos endPos;
Motor turnTable;
Motor tiltPanel;
SonnenStand sunpos;
Find_Sun FindSun;
void setup()
{
  Serial.begin(9600);

  turnTable.init_motor(D0, D3, 1);
  tiltPanel.init_motor(D7, D4, 2);
  FindSun.init_compass();
  // WiFi.begin(ssid, pass);
  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   Serial.println("Attempting to connect to Network named: ");
  //   Serial.println(ssid);
  //   delay(3000);
  // }
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  pinMode(A0, OUTPUT);
  // FindSun.start_pos();
}

void loop()
{
  sunpos.get_azimuth(sunpos.get_arr_pos());
  az = FindSun.get_current_azimuth();
  diode = (analogRead(A0) * 5) / 1024.0;
  offset = FindSun.offset_to_Sun();

  // check_rotation=FindSun.check_rotation();

  Serial.println(analogRead(A0));

  // if(check_rotation==0)
  //   FindSun.check_tilt();

  // postData = "kompass=" + (String)az;
  // postData += "&diode=" + (String)diode;
  // postData += "&offset=" + (String)offset;
  // if (client.connect(server, 9887))
  // {
  //   client.println("POST / HTTP/1.1");
  //   client.println("Content-Type: application/x-www-form-urlencoded");
  //   client.print("Content-Length: ");
  //   client.println(postData.length());
  //   client.println();
  //   client.print(postData);
  // }
  // if (client.connected())
  // {
  //   client.stop();
  // }
  // delay(100);
}
