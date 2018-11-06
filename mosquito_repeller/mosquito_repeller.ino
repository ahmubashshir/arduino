int speaker = 9;
int frequency = 31000;
int speaker2 = 11;
int frequency2 = 31000;

void setup(){
  pinMode(speaker, OUTPUT);
  pinMode(speaker2, OUTPUT);
}

void loop(){
  tone(speaker, frequency, 1000);
  tone(speaker2, frequency2, 1000);
}
