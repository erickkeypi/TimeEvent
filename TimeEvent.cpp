/*
Copyright 2019 Erick Rafael Garcia Martinez

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "TimeEvent.h"

TimeEvent::TimeEvent(){
  estado = _TIME_EVENT_STOP;
  repetir = false;
  cuenta = 0;
  segAct = false;
}
TimeEvent::TimeEvent(unsigned long _periodo){
  TimeEvent();
  periodo = _periodo;
}

TimeEvent::TimeEvent(unsigned long _periodo,int modo){
  TimeEvent();
  periodo = _periodo;
  if(modo){
    segAct = true;
  }
}

void TimeEvent::setPeriod(unsigned long _periodo){
  periodo = _periodo;
}

boolean TimeEvent::run(){

  if(estado == _TIME_EVENT_START){
    if(segAct){
      cuenta = (millis() - tiempo)/1000;
    }else{
      cuenta = millis() - tiempo;
    }

    if((cuenta >= periodo)){
      tiempo = millis();
      if(!repetir){
        estado = _TIME_EVENT_STOP;
      }

      return true;
    }
  }
  return false;
}

void TimeEvent::run(void(fc)(void)){
  if(run()){
    fc();
  }
}

unsigned long TimeEvent::count(){
  return cuenta;
}

void TimeEvent::stop(){
  estado = _TIME_EVENT_STOP;
}

void TimeEvent::start(){
  if(estado == _TIME_EVENT_PAUSE){
    tiempo = millis() - cuenta;
  } else if (estado != _TIME_EVENT_START){
    tiempo = millis();
  }
  estado = _TIME_EVENT_START;
}

void TimeEvent::pause(){
  estado = _TIME_EVENT_PAUSE;
}

void TimeEvent::repeat(){
  repetir = true;
}

void TimeEvent::noRepeat(){
  repetir = false;
}

byte TimeEvent::state(){
  return estado;
}
