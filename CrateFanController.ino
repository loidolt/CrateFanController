/*
* Crate Fan Controller V1
* Chris Loidolt, 2017
*/
#include <DallasTemperature.h>
#include <OneWire.h>

// DS18B20 setup
#define ONE_WIRE_BUS 3
OneWire ds(ONE_WIRE_BUS);
DallasTemperature sensors(&ds);

// Fan Pin
int fan = 0;

float idealTemp = 26;


void setup(){
  delay(1000);

  pinMode(fan, OUTPUT);

  sensors.begin();
}


void loop(){
  
 sensors.requestTemperatures(); // Send the command to get temperature reading

 if(sensors.getTempCByIndex(0) > idealTemp )
    { 
      digitalWrite(fan, HIGH);
      delay(100);
    }
else
    {
      analogWrite(fan, LOW);
      delay(100);
    } 
  delay(3000);
}
