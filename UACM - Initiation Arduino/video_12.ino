#include <Servo.h>

Servo servo_3;

Servo servo_5;

void setup()
{
  pinMode(A0, INPUT);
  servo_3.attach(3);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A1, INPUT);
  servo_5.attach(5);

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  if (digitalRead(A0) == 1) {
    servo_3.write(90);
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    servo_3.write(0);
  }

  if (digitalRead(A1) == 1) {
    servo_5.write(90);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  } else {
    servo_5.write(0);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}