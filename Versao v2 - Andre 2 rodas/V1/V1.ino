#include <Servo.h> 
int velocidade = 0;
int velocidadeInicial = 70;
int velFrente = 85;
int velTras = 55;
Servo DIRF;  

void setup() 
{
  Serial.begin(9600);
  Serial.println("Inicio");
  DIRF.attach(13);
  DIRF.write(70);
  delay(3000);
  DIRF.write(150);
  delay(3000);
  DIRF.detach();
  
}
void loop() 
{

}
