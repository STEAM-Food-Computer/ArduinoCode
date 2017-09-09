#include <WaterSensor.h>
#include <WateringApparatus.h>
#include <WaterPump.h>
#include <GrowLight.h>
#include <Fan.h>

GrowLight g(8, 1000);
WaterPump *w = new WaterPump(9, 1000);
WaterSensor *s[2];


void setup() {
  s[0] = new WaterSensor(10, 1);
  s[1] = new WaterSensor(11, 2);
  WateringApparatus::addSensor((*s)[0]);
  WateringApparatus::addSensor((*s)[1]);
  WateringApparatus::addWaterPump(*w);

}

void loop() {
 WateringApparatus::pump();
}
