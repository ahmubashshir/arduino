const uint8_t sensor = A0 , relay = 3;


void delay_m(unsigned m)
{
  long t = m * 60;
  while (t >= 0) {
    t -= 1;
    delay(1000);
  }
}
void pump(uint8_t sp, uint8_t rp)
{
  if (analogRead(sp) <= 400) { //moiester
    digitalWrite(rp, HIGH);
    delay_m(5);
    digitalWrite(rp, LOW);

  }
  digitalWrite(rp, LOW);

}



void setup() {

  pinMode(sensor, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  pump(sensor, relay);

}

void loop() {
  delay_m(60);
  if (Serial.available()) {
    Serial.print("Moiester:");
    Serial.write(analogRead(sensor));
  }
  pump(sensor,relay);
}

