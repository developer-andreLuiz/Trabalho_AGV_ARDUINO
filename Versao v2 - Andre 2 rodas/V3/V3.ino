#include <Servo.h>
int led = 13;
int porta_esquerda = 8;
int porta_direita = 10;
String desligar = "0*0";
Servo roda_esquerda;
Servo roda_direita;

//Ré = 55 ------- 10
//parado = 70
//Frente = 85 ------165

int RpmMaximo = 165;
int RpmMinimo = 10;
int RpmParado = 70;



void setup ()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  roda_esquerda.attach(porta_esquerda);
  roda_direita.attach(porta_direita);
  delay(10);
  roda_esquerda.write(RpmParado);
  roda_direita.write(RpmParado);
  delay(1000);
  digitalWrite(led, HIGH);
}

void loop ()
{
  while (Serial.available() > 0)
  {
    String txt = Serial.readString();
    int posicao = txt.indexOf('*');
    String vD = txt.substring(0, posicao);
    String vE = txt.substring(posicao + 1);
    int ValorDireita = vD.toInt();
    int ValorEsquerda = vE.toInt();
    if (ValorDireita > 0 && ValorEsquerda > 0 && ValorDireita < 166 && ValorEsquerda < 166)
    {
      roda_direita.write(ValorDireita);
      roda_esquerda.write(ValorEsquerda);
    }
    if (ValorDireita == 1000 && ValorEsquerda == 1000)
    {
      roda_esquerda.attach(porta_esquerda);
      roda_direita.attach(porta_direita);
      delay(10);
      roda_esquerda.write(RpmParado);
      roda_direita.write(RpmParado);
      delay(1000);
      digitalWrite(led, HIGH);
    }
    if (ValorDireita == 500 && ValorEsquerda == 500)
    {
      roda_direita.detach();
      roda_esquerda.detach();
      digitalWrite(led, LOW);
    }
  }
}
