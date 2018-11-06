#include <ArduinoJson.h>
boolean serial;
boolean light;
StaticJsonBuffer<50> jsonBuffer;
JsonObject root;
void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(6,OUTPUT);
}

void loop() {
  // print the string when a newline arrives:
  if (serial) {
      root = jsonBuffer.parseObject(Serial);
      light=root["motor"];
      serial=false;
  }
  if(light) digitalWrite(6,HIGH);
  else digitalWrite(6,LOW);
 Serial.println(light);
 delay(100);
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  serial=true;
}



