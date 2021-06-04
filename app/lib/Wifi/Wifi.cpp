#include "Wifi.h"


char ssid[] = "ADD_SSID";
char pass[] = "ADD_PASSWORD";
char server[] = "arduino.ayhamcloud.de";

void Wireless::Wifi_setup()
{
  rtc_temp_only.begin();
  turnTable.init_motor(D0, D3, 1);
  tiltPanel.init_motor(D7, D4, 2);
  endPos.init_sensors(D6, D5);
  FindSun.init_compass();
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
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void Wireless::send_Data()
{
  if (ticks == 5)
  {
    if (endPos.getPosPhiDown() == 0)
      endpos_val = "Down";
    else if (endPos.getPosPhiUp() == 1)
      endpos_val = "Up";
    else
      endpos_val = "Tilted";

    postData = "kompass=" + (String)az;
    postData += "&diode=" + (String)diode;
    postData += "&offset=" + (String)offset;
    postData += "&temperature" + (String)temperature;
    postData += "&endpost=" + (String)endpos_val;
    postData += "&status=" + (String)gen_status;
    postData += "&tiltPanel=" + (String)tiltPanel.get_rot();
    postData += "&turnTable=" + (String)turnTable.get_rot();

    if (client.connect(server, 80))
    {
      client.println("POST / HTTP/1.1");
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
    ticks = 0;
    delay(100);
  }
}