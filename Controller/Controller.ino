#include <WaterSensor.h>
#include <WateringApparatus.h>
#include <WaterPump.h>
#include <GrowLight.h>
#include <Fan.h>
#include <HumidThermoSensor.h>
#include <TempHumidityControl.h>


HumidThermoSensor* tr = new HumidThermoSensor(11);
GrowLight g(8, 1000);
WaterPump w(9);
WaterSensor *s[2];


void setup() {
  s[0] = new WaterSensor(12, 0);
  s[1] = new WaterSensor(13, 1);
  Serial.begin(9600);
  WateringApparatus::addSensor(*s[0]);
  WateringApparatus::addSensor(*s[1]);
  WateringApparatus::addWaterPump(w);
  TempHumidityControl::addSensor(*tr);

}

void loop() {
 WateringApparatus::pump();
 TempHumidityControl::regulate();
}
