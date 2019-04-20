#include "TimeEvent.h"

TimeEvent evento = TimeEvent(1000);

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  evento.setFrecuency(5000);
  evento.start();
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
    else if(m == 'r'){
      evento.repeat();
    }
    else if(m == 'n'){
      evento.noRepeat();
    }
    else if(m == 'c'){
      Serial.println(evento.count());
    }
    else if(m == 'q'){
      Serial.println(evento.state());
    }
  }
}

void parpadear(){
  digitalWrite(13,!digitalRead(13));
}
