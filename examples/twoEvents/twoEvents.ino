#include "TimeEvent.h"

TimeEvent evento1 = TimeEvent(1000);
TimeEvent evento2 = TimeEvent(1100);

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  evento1.repeat();
  evento2.repeat();
  evento1.start();
  evento2.start();
}

void loop(){

  if(evento1.run()){
    parpadear();
  }

  evento2.run(mensaje);

}

void parpadear(){
  digitalWrite(13,!digitalRead(13));
}

void mensaje(){
  Serial.println("Hola Mundo");
}
