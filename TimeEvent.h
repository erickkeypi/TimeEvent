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

#ifndef _TIME_EVENT_H
#define _TIME_EVENT_H

#include "Arduino.h"
#define _TIME_EVENT_START 0
#define _TIME_EVENT_STOP 1
#define _TIME_EVENT_PAUSE 2


class TimeEvent {
private:
  unsigned long tiempo, frecuencia, cuenta;
  byte estado;
  boolean repetir;


public:
  TimeEvent(unsigned long);
  void setFrequency(unsigned long);
  boolean run();
  void run(void(fc)(void));
  unsigned long count();
  void stop();
  void start();
  void pause();
  void repeat();
  void noRepeat();
  byte state();
};

#endif
