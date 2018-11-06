void moveStop() {   
  analogWrite(Motor_B_Enable, 0);
  analogWrite(Motor_A_Enable, 0);
  digitalWrite(Motor_A_Reverse, LOW);
  digitalWrite(Motor_B_Reverse, LOW);
  digitalWrite(Motor_A_Forward, LOW);
  digitalWrite(Motor_B_Forward, LOW);
  digitalWrite(red_Led, LOW);
  digitalWrite(green_Led, LOW);
  digitalWrite(yellow_Led, LOW);
  digitalWrite(white_Led, LOW);
}  
   
void moveForward() { 
  analogWrite(Motor_B_Enable, 160);
  analogWrite(Motor_A_Enable, 190);
  digitalWrite(Motor_A_Reverse, LOW);
  digitalWrite(Motor_B_Reverse, LOW);
  digitalWrite(Motor_A_Forward, HIGH);
  digitalWrite(Motor_B_Forward, HIGH);
  digitalWrite(red_Led, HIGH);
  digitalWrite(green_Led, LOW);
  digitalWrite(yellow_Led, LOW);
  digitalWrite(white_Led, LOW);
}  
void moveBackward() {
  analogWrite(Motor_B_Enable, 190);
  analogWrite(Motor_A_Enable, 190);
  digitalWrite(Motor_A_Reverse, HIGH);
  digitalWrite(Motor_B_Reverse, HIGH);
  digitalWrite(Motor_A_Forward, LOW);
  digitalWrite(Motor_B_Forward, LOW);
  digitalWrite(red_Led, LOW);
  digitalWrite(green_Led, HIGH);
  digitalWrite(yellow_Led, LOW);
  digitalWrite(white_Led, LOW);
  
}    
void turnRight() { 
    analogWrite(Motor_A_Enable, 190);
    analogWrite(Motor_B_Enable, 0);
    digitalWrite(Motor_A_Reverse, LOW);
    digitalWrite(Motor_A_Forward, HIGH); 
    digitalWrite(red_Led, LOW);
    digitalWrite(green_Led, LOW);
    digitalWrite(yellow_Led, LOW);
    digitalWrite(white_Led, HIGH);
}  
  
void turnLeft() { 
    analogWrite(Motor_B_Enable, 190);
    analogWrite(Motor_A_Enable, 0);
    digitalWrite(Motor_B_Reverse, LOW); 
    digitalWrite(Motor_B_Reverse, LOW);
    digitalWrite(Motor_B_Forward, HIGH); 
    digitalWrite(red_Led, LOW);
    digitalWrite(green_Led, LOW);
    digitalWrite(yellow_Led, HIGH);
    digitalWrite(white_Led,LOW);
}
void lookStraight() 
{ 
    myservo.write(100);  
}
int lookRight() 
{ 
    myservo.write(30);   
    int distance = readPing(); 
    delay(100); 
    //myservo.write(100);  
    return distance;
}
int lookLeft() 
{ 
    myservo.write(170);  
    delay(800); 
    int distance = readPing(); 
    delay(100); 
    //myservo.write(100);  
    return distance; 
}

