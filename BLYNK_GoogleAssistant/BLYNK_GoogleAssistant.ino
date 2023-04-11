#define BLYNK_TEMPLATE_ID "TMPLKgeIl47u"
#define BLYNK_DEVICE_NAME "Robotic Arm GOOGLE ASSISTANT"
#define BLYNK_AUTH_TOKEN "RZICZOOiy9ASVKwOcK7RkJ-Xv2YR9OhX"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

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
  int openOrClose = param.asInt();
  if(openOrClose == 1){
    servGarra.write(60); 
  }else{
    servGarra.write(40); 
  }
}

BLYNK_WRITE(V1){
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

BLYNK_WRITE(V2){
  int rotacao = param.asInt();
  int pos;

  if(rotacao == 1){
    for(pos = 90; pos <= 180; pos += 1){
      servBase.write(pos);
    }
      
    for(pos = 180; pos >= 90; pos -= 1 ){
        servBase.write(pos);
    }
      
    for(pos = 90; pos >= 0; pos -= 1){
        servBase.write(pos);
    }
  
    for(pos = 0; pos <= 90; pos +=1 ){
        servBase.write(pos);
    }
  }
}

BLYNK_WRITE(V3){
  servGarra.write(param.asInt());
}

BLYNK_WRITE(V4){
  servQuadrado.write(param.asInt());
}

BLYNK_WRITE(V5){
  servTrapezio.write(param.asInt());
}

BLYNK_WRITE(V6){
  servBase.write(param.asInt());
}

void loop() {
  Blynk.run();

}
