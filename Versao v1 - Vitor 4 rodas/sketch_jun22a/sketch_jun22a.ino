#include <Servo.h> 


int velESQ = 0;         // variable to store the servo speed
int velDIR = 0;         // variable to store the servo speed
int velESQi = 70;        // servo 1 initial speed
int velDIRi = 70;      // servo 2 initial speed
int velFrente = 85;
int velTras = 55;
int incomingByte = 0;  // for incoming serial data
int currentvelESQ;      //current speed servo 1
int currentvelDIR;      //current speed servo 2


Servo ESQF;  // create servo object to control a servo. A maximum of eight servo objects can be created 
Servo DIRF;  
Servo DIRT;
Servo ESQT;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Arduino code starting");

  ESQT.attach(9);  // attaches the servo on pin 9 to the servo ESQT object 
  DIRT.attach(10);  // attaches the servo on pin 10 to the servo DIRT object 
  ESQF.attach(8);  // attaches the servo on pin 8 to the servo ESQF object 
  DIRF.attach(11);  // attaches the servo on pin 11 to the servo DIRF object
  ESQF.write(velESQi); //set the servo speed to 0 
  DIRF.write(velDIRi); //set the servo speed to 0 
  ESQT.write(velESQi); //set the servo speed to 0 
  DIRT.write(velDIRi); //set the servo speed to 0 

  /* ascii codes for the keys to de used:
   a = 97
   s= 115
   d = 100
   w = 119
   x = 120
   */

}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

  switch(incomingByte){
    case 97: //a
      if(velESQ != velESQi){
        velESQ=velESQi;
        velDIR=velDIRi;
        ESQF.write(velESQ);
        DIRF.write(velDIR);
        ESQT.write(velESQ);
        DIRT.write(velDIR);
        currentvelESQ = ESQT.read();
        currentvelDIR = DIRT.read();
        Serial.print("a apertado. Robo estava se movendo. Parando os dois lados. Lado ESQ: ");
        Serial.println(currentvelESQ);
        Serial.print(" / Lado DIR: ");
        Serial.println(currentvelDIR);
        break;    
      }
      
      velESQ = velTras;
      velDIR = velFrente;
      ESQF.write(velESQ);
      DIRF.write(velDIR);
      ESQT.write(velESQ);
      DIRT.write(velDIR);
      currentvelESQ = ESQT.read();
      currentvelDIR = DIRT.read();
      Serial.print("a apertado. Robô vai girar para esquerda: ");
      Serial.println(currentvelESQ);
      Serial.println(currentvelDIR);
      break;    
      
              
    case 100: //d
      if(velESQ != velESQi){
        velESQ=velESQi;
        velDIR=velDIRi;
        ESQF.write(velESQ);
        DIRF.write(velDIR);
        ESQT.write(velESQ);
        DIRT.write(velDIR);
        currentvelESQ = ESQT.read();
        currentvelDIR = DIRT.read();
        Serial.print("d apertado. Robo estava se movendo. Parando os dois motores. Lado ESQ: ");
        Serial.println(currentvelESQ);
        Serial.print(" / Lado DIR:  ");
        Serial.println(currentvelDIR);
        break;    
      }
      
      velESQ = velFrente;
      velDIR = velTras;
      ESQF.write(velESQ);
      DIRF.write(velDIR);
      ESQT.write(velESQ);
      DIRT.write(velDIR);
      currentvelESQ = ESQT.read();
      currentvelDIR = DIRT.read();
      Serial.print("d apertado. Robô vai girar para direita. Lado ESQ: ");
      Serial.println(currentvelESQ);
      Serial.print(" / Lado DIR: ");
      Serial.println(currentvelDIR);
      break; 

      
    case 119: //w
      if(velESQ != velESQi){
        velESQ=velESQi;
        velDIR=velDIRi;
        ESQF.write(velESQ);
        DIRF.write(velDIR);
        ESQT.write(velESQ);
        DIRT.write(velDIR);
        currentvelESQ = ESQT.read();
        currentvelDIR = DIRT.read();
        Serial.print("w apertado. Robo estava se movendo. Parando os dois motores. Lado ESQ: ");
        Serial.println(currentvelESQ);
        Serial.print(" / Lado DIR: ");
        Serial.println(currentvelDIR);
        break;    
      }
      
      velESQ = velFrente;
      velDIR = velFrente;
      ESQF.write(velESQ);
      DIRF.write(velDIR);
      ESQT.write(velESQ);
      DIRT.write(velDIR);
      currentvelESQ = ESQT.read();
      currentvelDIR = DIRT.read();
      Serial.print("w apertado. Robô vai andar para frente. Lado ESQ: ");
      Serial.println(currentvelESQ);
      Serial.print(" / Lado DIR: ");
      Serial.println(currentvelDIR);
      break; 

      
    case 115: //s
      if(velESQ != velESQi){
        velESQ=velESQi;
        velDIR=velDIRi;
        ESQF.write(velESQ);
        DIRF.write(velDIR);
        ESQT.write(velESQ);
        DIRT.write(velDIR);
        currentvelESQ = ESQT.read();
        currentvelDIR = DIRT.read();
        Serial.print("s apertado. Robo estava se movendo. Parando os dois motores. Lado ESQ: ");
        Serial.println(currentvelESQ);
        Serial.print(" / Lado DIR: ");
        Serial.println(currentvelDIR);
        break;    
      }
      
      velESQ = velTras;
      velDIR = velTras;
      ESQF.write(velESQ);
      DIRF.write(velDIR);
      ESQT.write(velESQ);
      DIRT.write(velDIR);
      currentvelESQ = ESQT.read();
      currentvelDIR = DIRT.read();
      Serial.print("s apertado. Robô vai girar para trás. Lado ESQ: ");
      Serial.println(currentvelESQ);
      Serial.print(" / Lado DIR: ");
      Serial.println(currentvelDIR);
      break; 

      
    default:
      incomingByte = 0;
    }
  //Serial.print("ESQ Current speed requested: ");
  //Serial.println(velESQ);
  //Serial.print("DIR Current speed requested: ");
  //Serial.println(velDIR);
  incomingByte = 0;
  }  
}
