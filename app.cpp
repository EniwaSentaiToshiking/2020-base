#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "Straight.h"

using namespace ev3api;

Tracer tracer;  // <4>
Clock clock;    // <5>
Straight straight;

void tracer_task(intptr_t exinf) { // <1>
  tracer.run(); // <2>
  ext_tsk();
}

void straight_task(intptr_t exinf) {
  const uint32_t duration = 2000;
  straight.forward();
  clock.sleep(duration);
  straight.backward();
  clock.sleep(duration);
}

void main_task(intptr_t unused) { // <1>
  const uint32_t duration = 100; // <2>
  

  tracer.init(); // <3>
  straight.init();
  // sta_cyc(TRACER_CYC); // <4>
  sta_cyc(STRAIGHT_CYC);

  while (!ev3_button_is_pressed(LEFT_BUTTON)) { // <1>
      clock.sleep(duration);   // <2>
  }

  // stp_cyc(TRACER_CYC); // <3>
  stp_cyc(STRAIGHT_CYC); // <3>
  straight.terminate();
  tracer.terminate(); // <4>
  ext_tsk(); // <5>
}

