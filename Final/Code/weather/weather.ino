#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include "WiFi.h"
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
char auth[] = "ftHN7PGvKixBS3p5TSlztcS-hBusABv-";//Enter your Auth token
char ssid[] = "TEAM01";//Enter your WIFI name
char pass[] = "IOTCLASS";//Enter your WIFI password

DHT dht(D1, DHT11);//(DHT sensor pin,sensor type)
BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();
  delay(4000);

  //Call the functions
  timer.setInterval(100L, DHT11sensor);
}

//Get the DHT11 sensor values
void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}


void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}