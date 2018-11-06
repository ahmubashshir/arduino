#include <EEPROM.h>
#include <LiquidCrystal.h>
#define day 255
#define evening 150
#define night 75
int sensorPin = A0;
int sensorValue = 0;
int infopin=8;
int relay = 7;
int bl = 6;
int cb = 0;
LiquidCrystal lcd(12, 11, 5 , 4, 3, 2);
void setup() {
  init_f();
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Status:  LDCC-v2");
  cls(lcd,1,0,5);
  cls(lcd,1,6,16);
  lcd.setCursor(0, 1);
  street_mode();
  delay(100);
}

