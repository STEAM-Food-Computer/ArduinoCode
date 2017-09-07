#include <WaterSensor.h>
#include <WaterPump.h>
#include <GrowLight.h>
#include <Fan.h>

GrowLight g(8, 1000);
WaterPump w(9, 1000);
Fan *f[2];
int num1 = 0;
int num2 = 0;
short denom1 = 0;
short denom2 = 0;
double movingAv1 = 0;
double movingAv2 = 0;
int track = 0;

void setup() {
  f[0] = new Fan(10, 2000);
  f[1] = new Fan(11, 2000);
  Serial.begin(9600);
}

void loop() {
  /*
  g.strobe();
  w.strobe();
  for(int i = 0; i < sizeof(f); i++)
    f[i]->strobe();*/
  if(millis()%500 == 0 && track++%4 == 0) {
    
    int input = analogRead(0);
    num1 += input;
    movingAv1 = ((double)num1)/((double)(++denom1));
    Serial.print("Sensor 1 Average: "); Serial.println(input);

    
    input = analogRead(1);
    num2 += input;
    movingAv2 = ((double)num2)/((double)(++denom2));
    Serial.print("Sensor 2 Average: "); Serial.println(input);


    //Serial.print("Sensor 1 Average: "); Serial.println((int)movingAv1);
    //Serial.print("Sensor 2 Average: "); Serial.println((int)movingAv2);
  }
}
