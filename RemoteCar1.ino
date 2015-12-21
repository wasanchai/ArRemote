/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myServo11;  
Servo myServo12; 
// create servo object to control a servo 
                // twelve servo objects can be created on most boards
 int VRPin1 = 0;
 int VRPin2 = 0;
 
 int val1;
 int val2;

int servo1=9;
int servo2=9;
int pos1 = 0;    // variable to store the servo position 
int pos2 = 0;
 
 
volatile int pwm1_value = 0;
volatile int prev1_time = 0;

volatile int pwm2_value = 0;
volatile int prev2_time = 0;

void setup() 
{ 
  myServo11.attach(servo1);  // attaches the servo on pin 9 to the servo object 
  myServo11.attach(servo2); 
  attachInterrupt(0, rising1, RISING);
  //attachInterrupt(1, rising2, RISING);
} 
 
void loop() 
{ 
  val1 = analogRead(VRPin1);
  val2 = analogRead(VRPin2);
  val1 = map(val1, 0, 1023, 0, 180);  
  myServo11.write(val1);   
  myServo11.write(val2); 
   delay(15);    
 } 
void rising1() {
  attachInterrupt(0, falling1, FALLING);
  prev1_time = micros();
}
 
void falling1() {
  attachInterrupt(0, rising1, RISING);
  pwm1_value = micros()-prev1_time;
  Serial.println(pwm1_value);
}
void rising2() {
  attachInterrupt(0, falling2, FALLING);
  prev2_time = micros();
}
 
void falling2() {
  attachInterrupt(0, rising2, RISING);
  pwm2_value = micros()-prev2_time;
  //Serial.println(pwm_value);
}
