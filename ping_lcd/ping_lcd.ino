/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * ends to +5V and ground
 */

// include the library code:
#include <LiquidCrystal.h>
#include <NewPing.h>

#define TRIGGER_PIN  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int duration=0;
char load[]={ '|','/','-'};
int step=0;
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("distance:");
  lcd.setCursor(0, 1);
  lcd.print(sonar.ping_cm());
  lcd.print(" cm");
  for(step=0;step<=2;step++)
  {
    lcd.setCursor(15,0);
    lcd.write(load[step]);
    delay(500);
  }
  lcd.setCursor(13,0);
  lcd.print(":-)");
  delay(1000);
}

