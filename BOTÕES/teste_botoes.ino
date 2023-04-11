// inclui bibilioteca do servomotor
#include <Servo.h> 

// define pinos dos servos
#define pinBase 4 //D2
#define pinQuad 14 //D5
#define pinTrap 15 //D8
#define pinGarr 5 //D1

// define pinos dos botões
#define pinBotaoGarra 16 //D0
#define pinBotaoQdLeft 0 //D3
#define pinBotaoQdRight 2 //D4
#define pinBotaoTpLeft 12 //D6
#define pinBotaoTpRight 13  //D7

// define as portas dos potenciometros
#define potBase A0


// nomeia os servos
Servo servBase,servQuadrado,servTrapezio,servGarra;

// cria as variavies dos angulos de cada motor
int motorBase;
int valorBotaoG, valorBotaoQR, valorBotaoQL, valorBotaoTR, valorBotaoTL;

unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 5000;

boolean auxGarra = true;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600); 

  // atribui pinos dos servos
  servBase.attach(pinBase);
  servQuadrado.attach(pinQuad);
  servTrapezio.attach(pinTrap);
  servGarra.attach(pinGarr);
    
  auxGarra = true; //garra aberta
  
  // atribui pinos dos botões
  pinMode(pinBotaoGarra, INPUT);
  pinMode(pinBotaoQdLeft, INPUT);
  pinMode(pinBotaoQdRight, INPUT);
  pinMode(pinBotaoTpLeft, INPUT);
  pinMode(pinBotaoTpRight, INPUT);
}

void loop() {
  //LEITURA DOS VALORES DOS BOTÕES
  valorBotaoG = digitalRead(pinBotaoGarra);
  valorBotaoQR = digitalRead(pinBotaoQdRight);
  valorBotaoQL = digitalRead(pinBotaoQdLeft);
  valorBotaoTR = digitalRead(pinBotaoTpRight);
  valorBotaoTL = digitalRead(pinBotaoTpLeft);

  // MOVIMENTO DA GARRA
  if(valorBotaoG == 1 && !auxGarra){
    
    for(int i = 40; i <= 60; i++){
      servGarra.write(i);
    } 
    
    //servoGarra.write(180);   //garra aberta    
    auxGarra = true;
  }
  else if(valorBotaoG == 1 && auxGarra){       
    
    for(int i = 60; i >= 40; i--){
      servGarra.write(i);
    }
    
    //servoGarra.write(0);    //garra fechada
    auxGarra = false;
  }
  
  // MOVIMENTO MOTOR DO QUADRADO
  if(valorBotaoQR == 1){
    for(int i = 50; i <= 145; i++){
      servQuadrado.write(i);
    }   
  }
  else if(valorBotaoQL == 1){
    for(int i = 145; i >= 50; i--){
      servQuadrado.write(i);
    }
  }
  
  // MOVIMENTO MOTOR DO TRAPÉZIO
  if(valorBotaoTR == 1){
    for(int i = 80; i <= 180; i++){
      servTrapezio.write(i);
    }   
  }
  else if(valorBotaoTL == 1){
    for(int i = 180; i >= 80; i--){
      servTrapezio.write(i);
    }
  }
}
