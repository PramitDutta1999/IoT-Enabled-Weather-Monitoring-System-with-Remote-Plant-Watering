#include <LiquidCrystal.h>
#include<Servo.h>
#include "DHT.h"
#define DHTPIN 8
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
Servo myservo;
int pos=0;
void setup() {
  dht.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("ETE-17");
  lcd.setCursor(0, 1);
  lcd.print("Group:3");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("ETE-416");
  lcd.setCursor(0, 1);
  lcd.print("IoT Project");
  delay(2000);
  lcd.clear();  
  myservo.attach(9);    
}

void loop() { 
  int H = dht.readHumidity();
  float T = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(T);
  lcd.print(" H:");
  lcd.print(H);
  delay(100);  
  if(H<50){
    for(pos=0;pos<=180;pos+=5){
      myservo.write(pos);
      lcd.setCursor(0, 1);
      lcd.print("Motor On ");
      delay(15);
    }
    for(pos=180;pos>=0;pos-=5){
      myservo.write(pos);
      delay(15);
    }   
  }
  else{   
    myservo.write(0);    
    lcd.setCursor(0, 1);
    lcd.print("Motor Off");    
  }    
}

