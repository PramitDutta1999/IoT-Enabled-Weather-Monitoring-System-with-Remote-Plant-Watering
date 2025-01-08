#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLQNF8LYfz"     //Paste your credentials here
#define BLYNK_DEVICE_NAME "Weather Monitoring and Plant Watering System"  //Paste your credentials here

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

char auth[] = "ftHN7PGvKixBS3p5TSlztcS-hBusABv-";//Paste auth token you copied
char ssid[] = "Galaxy A712896";///Enter your wifi name
char pass[] = "maisha11";// Enter wifi password

#define DHTPIN 2

#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
bool Relay = 0;
#define waterPump 26


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); //(true) for Fahrenheit
/*
  if(h>70){
     digitalWrite(waterPump, HIGH);      
  }else{
     digitalWrite(waterPump, LOW);    
  }
*/
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V1, h); // virtual pins
  Blynk.virtualWrite(V0, t); // virtual pins
}

void setup()
{
  Serial.begin(115200);
  delay(1000);
  pinMode(waterPump, OUTPUT);
  digitalWrite(waterPump, HIGH);
  //Blynk.begin(auth, ssid, pass);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}

//Get the button value
BLYNK_WRITE(V2) {
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(waterPump, LOW);
    Serial.println("Motor On");
  } else {
    digitalWrite(waterPump, HIGH);
    Serial.println("Motor Off");    
  }
  delay(5000);
}