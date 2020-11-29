#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ); 

int trigPin = 9;
int echoPin = 10;
int led = 13;
int gnd =3;
void setup() {
  
  Serial.begin(9600); 
 
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
 
 if((distance<=15)) 
  {
    digitalWrite(led, HIGH);
    motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor clockwise
 delay(15);
 //motor1.setSpeed(255); //Define maximum velocity
  //motor1.run(BACKWARD); //rotate the motor anti-clockwisem
   //delay(2000);

}
   else if(distance>15)
 {
     digitalWrite(led, LOW);
     motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
   
  delay(15);
   }
}
