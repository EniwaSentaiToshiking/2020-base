#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "Straight.h"
#include "WaitStart.h"

using namespace ev3api;

Tracer tracer;  // <4>
Clock clock;    // <5>
Straight straight;
WaitStart waitStart;

void tracer_task(intptr_t exinf) 
{ // <1>
  tracer.run(); // <2>
  ext_tsk();
}

void straight_task(intptr_t exinf) 
{
  const uint32_t duration = 2000;
  straight.forward();
  clock.sleep(duration);
  straight.backward();
  clock.sleep(duration);
}

void wait_start_task(intptr_t exinf) 
{
  sta_cyc(WAIT_START_CYC);
  ev3_led_set_color(LED_GREEN);
  if (ev3_button_is_pressed(LEFT_BUTTON))
  {
    ev3_led_set_color(LED_RED);
    // act_tsk(MAIN_TASK);
    // stp_cyc(WAIT_START_CYC);
  }
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

