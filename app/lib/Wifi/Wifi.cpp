#include "Wifi.h"

char ssid[] = "Jay_s_P30";
char pass[] = "00000000";
char server[] = "arduino.ayhamcloud.de";


void Wireless::Wifi_setup()
{
  rtc_temp_only.begin();
  turnTable.init_motor(D0, D3, 1);
  tiltPanel.init_motor(D7, D4, 2);
  endPos.init_sensors(D6, D5);
  FindSun.init_compass();
  sunpos.init_time();
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Attempting to connect to Network named: ");
    Serial.println(ssid);
    delay(3000);
  }
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.println(WiFi.gatewayIP());
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void Wireless::send_Data()
{
  endPos.read_pins();
  az = FindSun.get_current_azimuth();
  offset = FindSun.offset_to_Sun();
  temperature = rtc_temp_only.getTemperature();
  if (endPos.getPosPhiDown() == 0)
    endpos_val = "Down";
  else if (endPos.getPosPhiUp() == 1)
    endpos_val = "Up";
  else
    endpos_val = "Tilted";

  postData = "kompass=" + (String)az;
  postData += "&ldrlay=" + (String)FindSun.get_ldr0();
  postData += "&ldrup=" + (String)FindSun.get_ldr1();
  postData += "&offset=" + (String)offset;
  postData += "&temp=" + (String)temperature;
  postData += "&endpost=" + (String)endpos_val;
  postData += "&status=" + (String)gen_status;
  postData += "&tiltPanel=" + (String)tiltPanel.get_dir();
  postData += "&turnTable=" + (String)turnTable.get_rot();
  postData += "&sunpos=" + (String)sunpos.get_azimuth(sunpos.get_arr_pos());

  if (client.connect(server, 80))
  {
    client.println("POST / HTTP/1.1");
    client.println("HOST: arduino.ayhamcloud.de");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(postData.length());
    client.println();
    client.print(postData);
  }
  if (client.connected())
  {
    client.stop();
  }
  delay(100);
  Serial.println(postData);
}
int Wireless::gen_Status()
{
  gen_status = 0;
  return gen_status;
}