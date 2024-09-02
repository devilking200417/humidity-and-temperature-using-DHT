#include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
  


#include <LiquidCrystal.h>
#define DHTPIN 8
LiquidCrystal lcd(7,6,5,4,3,2);
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
char temperature[]="Temp=00.0C";
char humidity[]="RH=00.0%";
void setup()
{
  lcd.begin(16,2);
  dht.begin();
  
}
void loop()
{
  delay(1000);
  byte RH=dht.readHumidity();
  byte Temp=dht.readTemperature();
  if(isnan(RH)||isnan(Temp))
  {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("Error");
    return;
  }
  temperature[7]=Temp/10+48; 
  temperature[8]=Temp/10+48;
    temperature[11]=223;
    humidity[7]=RH/10+48;
    humidity[8]=RH%10+48;
    lcd.setCursor(90,0);
    lcd.print(temperature);
    lcd.setCursor(0,1);
    lcd.print(humidity);
}


  
