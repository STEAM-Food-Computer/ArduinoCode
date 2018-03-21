#include <WaterSensor.h>
#include <WateringApparatus.h>
#include <WaterPump.h>
#include <GrowLight.h>
#include <Fan.h>
#include <HumidThermoSensor.h>
#include <TempHumidityControl.h>
#include<JsonObject.h>
#include <SPI.h>
#include <Ethernet.h>


HumidThermoSensor* tr = new HumidThermoSensor(11);
GrowLight g(8, 1000);
WaterPump w(9);
WaterSensor *s[2];
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(10,0,1,3);
IPAddress ip(10,0,1,9);
EthernetClient client;


void setup() {
  s[0] = new WaterSensor(12, 0);
  s[1] = new WaterSensor(13, 1);
  Serial.begin(9600);
  WateringApparatus::addSensor(*s[0]);
  WateringApparatus::addSensor(*s[1]);
  WateringApparatus::addWaterPump(w);
  TempHumidityControl::addSensor(*tr);
  Ethernet.begin(mac, ip);
  if(client.connect(server, 5010)) {
    Serial.println("Food Computer Connected to Server");
  }
  else {
    Serial.println("Connection Failed, will try again later");
  }

}

void loop() {
 WateringApparatus::pump();
 TempHumidityControl::regulate();
 sendDataToServer(millis());
}

void sendDataToServer(long currTime) {
//make this send stuff only in intervals
  JsonObject j;
  j.add('humidity', TempHumidityControl::getHumidityAverage());
  j.add('temperature', TempHumidityControl::getTempAverage());
  j.add('moistureLevel',WateringApparatus::getAllSensorAverage());
  j.add('lightStatus',true);
  j.add('fanStatus', true);
  if(client.connected()) {
    client.write(j.stringify().c_str());
    Serial.println("Food computer data sent to server!");
  }
  else {
    Serial.println("Food computer not connected, retrying connection right now.");
    if(client.connect(server, 5010)){
      Serial.println("Client connected");
    }
    else {
      Serial.println("Connection Failed, will try again later");
    }
  }
    
}


