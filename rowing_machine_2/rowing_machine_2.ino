#include <Servo.h>
#include<ZyroScope.h>
#include<math.h>
#define Pi 3.1415926535
#define ZyroStdPos Pi/2
#define k 0.0005 //constant
const zyroPin=5,servoX=3,servoY=4;
float zyroVal;
void setup() {
  Zyro z1;
  z1.begin(zyroPin);
  Servo ServoX,ServoY;
  ServoX.attach(servoX);ServoY.attach(servoY);
}

void loop() {
  // put your main code here, to run repeatedly:
  ServoX.write(something)
  zyroVal=z1.readX();
  ServoY.write(sin(k*(ZyroStdPos-zyroVal)));
}
