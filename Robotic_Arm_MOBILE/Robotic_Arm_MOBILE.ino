#define BLYNK_TEMPLATE_ID "TMPLdm4_5fE5"
#define BLYNK_DEVICE_NAME "Robotic Arm MOBILE"
#define BLYNK_AUTH_TOKEN "JsZcrWdvPdhc0Gju6dhk9hkcZbaQSa12"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

//Cria um objeto do tipo Servo para que possamos utilizar as funções da biblioteca <Servo.h>.
Servo servGarra, servQuadrado, servTrapezio, servBase;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MARK I";
char pass[] = "[20201218]";



void setup() {
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  servGarra.attach(5, 500, 2500); //NodeMCU D1 pin
  servQuadrado.attach(14, 500, 2500); //NodeMCU D5 pin
  servTrapezio.attach(15, 500, 2500); //NodeMCU D8 pin
  servBase.attach(4, 500, 2500); //NodeMCU D2 pin

}

BLYNK_WRITE(V0){
  servGarra.write(param.asInt());
}


BLYNK_WRITE(V1){
  servQuadrado.write(param.asInt());
}


BLYNK_WRITE(V2){
  servTrapezio.write(param.asInt());
}


BLYNK_WRITE(V3){
  servBase.write(param.asInt());
}

BLYNK_WRITE(V4){
  int demonstracao = param.asInt();
  int pos;
  if(demonstracao == 1){
    //PRIMEIRO CICLO

    //MOVIMENTOS BASE
    for(pos = 90; pos <= 180; pos += 1){
      servBase.write(pos);
    }
    
    for(pos = 180; pos >= 90; pos -= 1 ){
      servBase.write(pos);
    }
    //MOVIMENTO SERVO QUADRADO
    for(pos = 50; pos <= 145; pos += 1){
      servQuadrado.write(pos);
    }

    for(pos = 145; pos >= 50; pos -= 1){
      servQuadrado.write(pos);
    }
    //MOVIMENTO 1 GARRA
    for(pos = 60; pos >= 40; pos -= 1){
      servGarra.write(pos);
    }

    for(pos = 40; pos <= 60; pos += 1){
      servGarra.write(pos);
    }
    //MOVIMENTO SERVO TRAPÉZIO
    for(pos = 80; pos <= 110; pos += 1){
      servTrapezio.write(pos);
    }
    for(pos = 60; pos >= 40; pos -= 1){
      servGarra.write(pos);
    }
    for(pos = 110; pos <= 145; pos += 1){
      servTrapezio.write(pos);
    }
    for(pos = 40; pos <= 60; pos += 1){
      servGarra.write(pos);
    }
    for(pos = 145; pos >= 80; pos -= 1){
      servTrapezio.write(pos);
    }
    
    //SEGUNDO CICLO

    //MOVIMENTO BASE
    for(pos = 90; pos >= 0; pos -= 1){
      servBase.write(pos);
    }

    for(pos = 80; pos <= 110; pos += 1){
      servTrapezio.write(pos);
    }
    for(pos = 50; pos <= 120; pos += 1){
      servQuadrado.write(pos);
    }
    for(pos = 60; pos >= 40; pos -= 1){
      servGarra.write(pos);
    }
    for(pos = 40; pos <= 60; pos += 1){
      servGarra.write(pos);
    }
    for(pos = 110; pos >= 80; pos -= 1){
      servTrapezio.write(pos);
    }
    for(pos = 120; pos >= 50; pos -= 1){
      servQuadrado.write(pos);
    }
    
    
    for(pos = 0; pos <= 90; pos +=1 ){
      servBase.write(pos);
    }
  }
}

void loop() {
  Blynk.run();

}
