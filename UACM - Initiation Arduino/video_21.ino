#include <Servo.h>

Servo servo_3;

void setup()
{
  pinMode(A0, INPUT);
  servo_3.attach(3);

}

void loop()
{
  servo_3.write(map(analogRead(A0), 0, 1023, 120, 20));
  delay(10); // Delay a little bit to improve simulation performance
}