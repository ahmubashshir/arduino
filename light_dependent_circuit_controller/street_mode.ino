void street_mode()
{
  lcd.setCursor(0, 1);
  sensorValue = 10*analogRead(sensorPin)/15;;
  Serial.println(sensorValue);
  cls(lcd,1,0,5);
  cls(lcd,1,6,16);
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);
  lcd.setCursor(5, 1);
  if (sensorValue < 500)
  {
    analogWrite(bl, night);
    digitalWrite(relay, HIGH);
    Serial.println("On:Night");
    lcd.setCursor(6, 1);
    lcd.write("n:Night");
  }
  else if (sensorValue < 600)
  {
    analogWrite(bl, evening);
    Serial.println("On:Evening");
    lcd.setCursor(6, 1);
    lcd.print("n:Evening");
    digitalWrite(relay, HIGH);
  }
  else if (sensorValue < 750)
  {
    analogWrite(bl, day);
    Serial.println("Off:Midday");
    lcd.setCursor(6, 1);
    lcd.print("ff:Midday");
    digitalWrite(relay, LOW);
  }
  else if (sensorValue < 850)
  {
    analogWrite(bl, day);
    Serial.println("Off:Morning");
    lcd.setCursor(6, 1);
    lcd.print("ff:Morning");
    digitalWrite(relay, LOW);
  }
  else if (sensorValue > 850)
  {
    analogWrite(bl, day);
    Serial.println("Off:Noon");
    lcd.setCursor(6, 1);
    lcd.print("ff:Noon");
    digitalWrite(relay, LOW);
  }
}
