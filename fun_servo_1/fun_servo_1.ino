#include <Servo.h>
int i=0;
bool zero=true;
Servo fb;
Servo rl;
void setup() {
  fb.attach(5);
  rl.attach(6);
  rl.write(0);
  fb.write(180);
}

void loop() {
  fb.write(i);
  rl.write(180-i);
  delay(2);
  if(zero) i++;
  else i--;
  if(i==180) zero=false;
  if(i==0) zero=true;
}
