/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
 clears it.
 
 A good test for this is to try it with a GPS receiver 
 that sends out NMEA 0183 sentences. 
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String tmp="";
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(100);
  tmp.reserve(100);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) { 
    stringComplete = false;
    inputString=tmp;
    tmp="";
    Serial.print("arduino@arduino-uno ~ $ ");
    if(inputString=="") Serial.print("\n");
    Serial.print(inputString);
    if(inputString=="shout"){
      digitalWrite(3,HIGH);
      Serial.print("\n  Shouting\n");
    }else if (inputString=="shutup"){
      digitalWrite(3,LOW);
      inputString="";
      Serial.print("\n  Shutting up\n");
    }
    else if (inputString=="exit")
    {
      digitalWrite(3,LOW);
      inputString="";
      Serial.print("\n  Exiting....\nProcess Returned 0(0x00)\n");
      delay(100);
      exit(0);
    }
    else if(inputString!="")Serial.print("\n"+inputString+": command not found\n");
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    if (inChar != '\n') tmp += inChar;
    else stringComplete = true;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it: 
  }
}


