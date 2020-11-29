#include <Servo.h>
Servo myservo;

int trigPin = 9;
int echoPin = 10;
int led = 13;


void setup() {
  
  Serial.begin(9600); 
  myservo.attach(6);
   pinMode(led, OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
 
 if((distance<=25)) 
  {
    digitalWrite(led, HIGH);
    myservo.write(100);                  // sets the servo position according to the scaled value
  delay(15);
}
   else if(distance>25)
 {
     digitalWrite(led, LOW);
     myservo.write(0);                  // sets the servo position according to the scaled value
  delay(15);
   }
}
