//#include <NewPing.h>
/*
  LiquidCrystal Library - Cursor
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD and
 uses the cursor()  and noCursor() methods to turn
 on and off the cursor.
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/LiquidCrystalCursor

 */

// include the library code:
#include <LiquidCrystal.h>
//#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
//#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
//#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,6,5,4,3,2);
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
  Serial.begin(9600);
  // Print a message to the LCD.
}

void loop() {
  // Turn off the cursor:
  lcd.setCursor(0,1);
  lcd.write("Distance:");
  delay(30);
  lcd.setCursor(0,2);
  lcd.write("100cm");
}

