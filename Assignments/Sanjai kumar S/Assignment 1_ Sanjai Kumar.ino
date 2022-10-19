#include <Servo.h>
int sensor_state = 0;
int distance = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
Servo servo_3;
void setup()
{
  pinMode(2, INPUT);
  servo_3.attach(3, 500, 2500);

  pinMode(7, OUTPUT);
  pinMode(A2, INPUT);
}
void loop()
{
  distance = 0.01723 * readUltrasonicDistance(5, 4);
  sensor_state = digitalRead(2);
  servo_3.write(0);
  
  if (sensor_state == HIGH) {
    servo_3.write(45);
    servo_3.write(0);
    delay(4000); 
    servo_3.write(0);
    tone(7, 123, 1000); 
  }
  if (distance <= 100) {
    servo_3.write(80);
    tone(7, 123, 1000); 
    delay(4000); 
    servo_3.write(0);
  } else {
    servo_3.write(0);
  }
  if (analogRead(A2) > 350) {
    servo_3.write(90);
    tone(7, 220, 10000); 
    servo_3.write(0);
  }
}
