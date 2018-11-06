#include <Adafruit_CircuitPlayground.h>
#define K(x) x*x*x
float X, Y;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  X = CircuitPlayground.motionX();
  Y = (X*X*X)/K(5);

  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  
  delay(1000);
}
