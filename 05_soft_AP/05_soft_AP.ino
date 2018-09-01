//esp8266作为软AP热点使用
#include <ESP8266WiFi.h>

IPAddress local_IP(192,168,8,20);
IPAddress gateway(192,168,8,9);
IPAddress subnet(255,255,255,0);

void setup()
{
  Serial.begin(9600);
  Serial.println();

 Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  
  Serial.print("Setting soft-AP ... ");
  boolean result = WiFi.softAP("胡杰爸爸的wifi", "myfather");
  if(result == true)
  {
    Serial.println("Ready");
  }
  else
  {
    Serial.println("Failed!");
  }

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
}

void loop()
{
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(3000);
}
