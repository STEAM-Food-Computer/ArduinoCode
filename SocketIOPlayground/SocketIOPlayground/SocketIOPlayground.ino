/*
  Web client

 This sketch connects to a website (http://www.google.com)
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe, based on work by Adrian McEwen

 */

#include <SPI.h>
#include <Ethernet.h>
#include <JsonObject.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(10,0,1,3);  // numeric IP for Google (no DNS)
//char server[] = "www.google.com";    // name address for Google (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(10,0,1,9);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;
JsonObject msg;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  msg.add('c', 25);
  msg.add("Humidity", 57.6);
  JsonObject jOb("log1",1);
  jOb.add("log2",2);
  msg.add("RandomData",jOb);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Ethernet.begin(mac, ip);

  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");
  Serial.println(msg.stringify());

  // if you get a connection, report back via serial:
  if (client.connect(server, 5010)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.write(msg.stringify().c_str());
    
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    while (true);
  }
}
