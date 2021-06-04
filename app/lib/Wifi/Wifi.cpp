#include "Wifi.h"

char ssid[] = "SSID";
char pass[] = "PASSWD";
char server[] = "arduino.ayhamcloud.de";
const char trustRoot[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDdzCCAl+gAwIBAgIEAgAAuTANBgkqhkiG9w0BAQUFADBaMQswCQYDVQQGEwJJ
RTESMBAGA1UEChMJQmFsdGltb3JlMRMwEQYDVQQLEwpDeWJlclRydXN0MSIwIAYD
VQQDExlCYWx0aW1vcmUgQ3liZXJUcnVzdCBSb290MB4XDTAwMDUxMjE4NDYwMFoX
DTI1MDUxMjIzNTkwMFowWjELMAkGA1UEBhMCSUUxEjAQBgNVBAoTCUJhbHRpbW9y
ZTETMBEGA1UECxMKQ3liZXJUcnVzdDEiMCAGA1UEAxMZQmFsdGltb3JlIEN5YmVy
VHJ1c3QgUm9vdDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKMEuyKr
mD1X6CZymrV51Cni4eiVgLGw41uOKymaZN+hXe2wCQVt2yguzmKiYv60iNoS6zjr
IZ3AQSsBUnuId9Mcj8e6uYi1agnnc+gRQKfRzMpijS3ljwumUNKoUMMo6vWrJYeK
mpYcqWe4PwzV9/lSEy/CG9VwcPCPwBLKBsua4dnKM3p31vjsufFoREJIE9LAwqSu
XmD+tqYF/LTdB1kC1FkYmGP1pWPgkAx9XbIGevOF6uvUA65ehD5f/xXtabz5OTZy
dc93Uk3zyZAsuT3lySNTPx8kmCFcB5kpvcY67Oduhjprl3RjM71oGDHweI12v/ye
jl0qhqdNkNwnGjkCAwEAAaNFMEMwHQYDVR0OBBYEFOWdWTCCR1jMrPoIVDaGezq1
BE3wMBIGA1UdEwEB/wQIMAYBAf8CAQMwDgYDVR0PAQH/BAQDAgEGMA0GCSqGSIb3
DQEBBQUAA4IBAQCFDF2O5G9RaEIFoN27TyclhAO992T9Ldcw46QQF+vaKSm2eT92
9hkTI7gQCvlYpNRhcL0EYWoSihfVCr3FvDB81ukMJY2GQE/szKN+OMY3EU/t3Wgx
jkzSswF07r51XgdIGn9w/xZchMB5hbgF/X++ZRGjD8ACtPhSNzkE1akxehi/oCr0
Epn3o0WC4zxe9Z2etciefC7IpJ5OCBRLbf1wbWsaY71k5h+3zvDyny67G7fyUIhz
ksLi4xaNmjICq44Y3ekQEe5+NauQrz4wlHrQMz2nZQ/1/I6eYs9HRCwBXbsdtTLS
R9I4LtD+gdwyah617jzV/OeBHRnDJELqYzmp
-----END CERTIFICATE-----
)EOF";
X509List cert(trustRoot);

void Wireless::Wifi_setup()
{
  configTime(2 * 3600, 0, "pool.ntp.org", "time.nist.gov");
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
  endPos.read_pins();
  az = FindSun.get_current_azimuth();
  temperature = rtc_temp_only.getTemperature();
  if (endPos.getPosPhiDown() == 0)
    endpos_val = "Down";
  else if (endPos.getPosPhiUp() == 1)
    endpos_val = "Up";
  else
    endpos_val = "Tilted";

  postData = "kompass=" + (String)az;
  postData += "&ldr0=" + (String)FindSun.get_ldr0();
  postData += "&ldr1=" + (String)FindSun.get_ldr1();
  postData += "&offset=" + (String)offset;
  postData += "&temp" + (String)temperature;
  postData += "&endpost=" + (String)endpos_val;
  postData += "&status=" + (String)gen_status;
  postData += "&tiltPanel=" + (String)tiltPanel.get_rot();
  postData += "&turnTable=" + (String)turnTable.get_rot();
  postData += "&sunpos=" + (String)sunpos.get_azimuth(sunpos.get_arr_pos());

  client.setTrustAnchors(&cert);
  if (client.connect(server, 443))
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
  Serial.println(postData);
  delay(100);
}
int Wireless::gen_Status()
{
  gen_status = 0;
  return gen_status;
}