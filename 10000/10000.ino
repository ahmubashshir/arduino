#include <NewPing.h> 
#include <Servo.h>   
#define TRIG_PIN 14  
#define ECHO_PIN 15  
#define MAX_DISTANCE 200  

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;     

boolean goesbBluetooth=false; 
int distance = 100; 

#define pingPin 9
#define Motor_A_Enable 6
#define Motor_A_Reverse 2
#define Motor_A_Forward 7

#define Motor_B_Enable 5
#define Motor_B_Reverse 3
#define Motor_B_Forward 4

// leds are very handy for testing

#define red_Led  10 // this led will lit up when the robot drives forward

#define green_Led  11// this led will lit up when the robot drives backward

#define yellow_Led 12// this led will lit up when the robot turns left

#define white_Led 13// this led will lit up when the robot turns right

int uS1distance;
int uS2distance;

void setup() {  
  pinMode(10,OUTPUT); 
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);
  pinMode(A4,INPUT);
  pinMode(Motor_A_Enable, OUTPUT);
  pinMode(Motor_A_Forward, OUTPUT);
  pinMode(Motor_A_Reverse, OUTPUT);
  pinMode(Motor_B_Enable, OUTPUT);
  pinMode(Motor_B_Forward, OUTPUT);
  pinMode(Motor_B_Reverse, OUTPUT);
  Serial.begin(9600);
  if(goesbBluetooth==false){
  myservo.attach(8);   
  myservo.write(100);  
  }
  delay(2000); 
  distance = readPing(); 
  delay(100); 
  distance = readPing(); 
  delay(100); 
  distance = readPing(); 
  delay(100); 
  distance = readPing(); 
  delay(100); 
  if(digitalRead(19)==HIGH)goesbBluetooth=true; 
  if(digitalRead(18)==HIGH)goesbBluetooth=false; 
}  
void loop() { 
 if(goesbBluetooth==false){
       int distanceR = 0; 
       int distanceL =  0; 
       delay(40); 
        
       if(uS1distance<=15) 
       {
        digitalWrite(13, LOW);
        moveStop(); 
        delay(100); 
        moveBackward(); 
        delay(1000); 
        moveStop(); 
        delay(400); 
        distanceR = lookRight(); 
        delay(400); 
        distanceL = lookLeft(); 
        delay(400);  
        lookStraight(); 
        delay(400);  
        if(distanceR>distanceL) 
        { 
          turnRight(); 
          moveStop(); 
        }else 
        { 
          turnLeft(); 
          moveStop(); 
        } 
       }else 
       { 
        moveForward(); 
        digitalWrite(13, HIGH);
       } 
       distance = readPing();
 }
 if(uS2cm(chkOldPing(pingPin))<1.5)
 {
        digitalWrite(11, HIGH);
        moveStop(); 
        delay(100); 
        moveBackward(); 
        delay(1000); 
        moveStop(); 
        delay(400);
  }
 
 else {
  myservo.detach(); 
      if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      Serial.write(data);
    switch (data)
    {
      case '1': //FORWARD
      moveStop();
         moveForward();
         break;
        
      case '2': //REVERSE
      moveStop();
         moveBackward(); 
        break;
        
      case '4': //LEFT
      moveStop();
        turnLeft();
        break;
        
      case '3': //RIGHT
moveStop();
turnRight();
        break;
        
      case 'e': 
        digitalWrite(13, HIGH);
        break;

      case 'f':   
        digitalWrite(13, LOW);
        break;

      case '8': //STOP
        moveStop();
        break;
        
      default: //If bluetooth module receives any value not listed above, both motors turn off
        moveStop();
        break;
    }
  }else{
    distance = readPing();
    delay(50);
          if(distance<20){
             moveStop(); 
            delay(100); 
            moveBackward(); 
            delay(800); 
            moveStop(); 
          }
  }
 }
}  
int readPing() {  
  delay(70); 
  int cm = sonar.ping_cm(); 
  if(cm==0) 
  { 
    cm = 250; 
  } 
  return cm; 
}  
int pingPing(){
  delay(70); 
  int cm = sonar.ping_cm(); 
  if(cm==0) 
  { 
    cm = 250; 
  } 
  return cm; 
}

