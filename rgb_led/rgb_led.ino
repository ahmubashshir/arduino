int i;
void setup()
{
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
}
void loop()
{
  for(i=0;i<=1024;i++){
    analogWrite(A0,i);
    delay(100);}
  for(i=0;i<=1024;i++){
    analogWrite(A1,i);
    delay(100);}
  for(i=1024;i>=0;i++){
    analogWrite(A0,i);
    delay(100);}
  for(i=1024;i>=0;i++){
    analogWrite(A1,i);
    delay(100);}
}
