#include <Servo.h>

int input = 13;
Servo Roda;  
int RpmMaximo = 7500;
int RpmMinimo = 0;
int ValorStart=70;
int ValorInputMaximo=0;
int ValorInputMinimo=0;


void setup () 
{
  Serial.begin(9600); 
  Roda.attach(input);
  delay(10);
  Serial.println("Inicio Calibragem");

  Roda.write(ValorStart);
  delay(3000);
  Serial.println("Pronto");
}

void loop () 
{
  while(Serial.available()>0)
  {
    int val = Serial.parseInt();
    if(val!=0)
    {
      Serial.println(val);
      Roda.write(val);
    }
    
    
  }

}
