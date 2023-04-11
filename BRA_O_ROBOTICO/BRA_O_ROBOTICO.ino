// inclui bibilioteca do servomotor
#include <Servo.h> 

// define pinos dos servos
#define pinServ1 2  //GARRA
#define pinServ2 3  //MOTOR DO QUADRADO
#define pinServ3 4  //MOTOR DO TRAPÉZIO
#define pinServ4 5  //MOTOR DA BASE

// define as portas dos potenciometros
#define pot1 A0   //GARRA
#define pot2 A1   //QUADRADO
#define pot3 A2   //TRAPÉZIO
#define pot4 A3   //BASE

// nomeia os servos
Servo serv1,serv2,serv3,serv4;

// cria as variavies dos angulos de cada motor
int motor1,motor2,motor3,motor4;

unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 1000;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600); 

  // atribui pinos dos servos
  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);
  
}

void loop(){

  // leitura dos potenciometros
  motor1 = map(analogRead(pot1),0,1023,5,20);   //GARRA
  motor2 = map(analogRead(pot2),0,1023,55,145);  //QUADRADO
  motor3 = map(analogRead(pot3),0,1023,110,180); //TRAPÉZIO
  motor4 = map(analogRead(pot4),0,1023,0,180);   //BASE

  // posicionamento dos potenciometros 
  serv1.write(motor1);  //GARRA
  serv2.write(motor2);
  serv3.write(motor3);
  serv4.write(motor4);

   if ((millis() - mostradorTimer) >= intervaloMostrador) {

  // envio para o monitor serial do posicionamentos dos motores
  Serial.println("**********************************************");
  
  Serial.print("Pot1:");
  Serial.print(analogRead(pot1));
  Serial.print(" Angulo Motor1:");
  Serial.println(motor1);

  Serial.print("Pot2:");
  Serial.print(analogRead(pot2));
  Serial.print(" Angulo Motor2:");
  Serial.println(motor2);

  Serial.print("Pot3:");
  Serial.print(analogRead(pot3));
  Serial.print(" Angulo Motor3:");
  Serial.println(motor3);

  Serial.print("Pot4:");
  Serial.print(analogRead(pot4));
  Serial.print(" Angulo Motor4:");
  Serial.println(motor4);

  mostradorTimer = millis();
  }

  // tempo de espera para recomeçar
  delay(100);

}
