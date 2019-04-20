#include "TimeEvent.h"

TimeEvent evento = TimeEvent(1000);

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  evento.repeat();
}

void loop(){
  evento.run(parpadear);
  if(Serial.available()>0){
    char m = Serial.read();
    if(m == 's'){
      evento.start();
    }
    else if(m == 't'){
      evento.stop();
    }
    else if(m == 'p'){
      evento.pause();
    }
  }
}

void parpadear(){
  digitalWrite(13,!digitalRead(13));
}
