#include <Servo.h>
Servo myservo; 
#define photocellPin A2
int photocellVal = 0; 
int minLight = 100;  
int pos = 0;
int reset = 0; 
int flag = 0 ; 

void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
  myservo.write(reset); 
}

void loop() {
  Serial.println(/*photocellVal*/pos); 
  photocellVal = analogRead(photocellPin);
  if(photocellVal < minLight){
      if(flag == 0){
          pos++;
          myservo.write(pos); 
          delay(5); 
          if(pos == 180)
              flag = 1 ;
      }
      if(flag == 1){
          pos--;
          myservo.write(pos); 
          delay(5); 
          if(pos == 0)
              flag = 0 ;
      }
  }
}

