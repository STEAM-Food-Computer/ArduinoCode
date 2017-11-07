#include <dht.h>
#define DHT11_PIN 8
dht DHT;
int tempVal = 0;
int humidity = 0;
long readVal = 0;
float x = 61.4;
void setup() {
  Serial.begin(9600);
  readVal = millis() + 4000;
}

void loop() {

if (millis() > readVal) {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature: "); Serial.println(DHT.temperature);
  Serial.print("Humidity: "); Serial.println(DHT.humidity);
  Serial.print(x);
  readVal = millis() + 4000;
}

}
