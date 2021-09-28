#include <Servo.h>

const uint8_t VescOutputPin = 11;

const uint8_t PotentiometerPin = A0;

Servo esc;

void setup () {
  Serial.begin(9600); 
  esc.attach (VescOutputPin);

  esc.writeMicroseconds (1500);

}

 void loop () {

  Serial.println(analogRead (PotentiometerPin));
  esc.writeMicroseconds (map (analogRead (PotentiometerPin), 0, 1023, 1000, 2000));

}
