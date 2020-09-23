#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
}

void PlaygroundGameState::init()
{
  init_f("PlaygroundGameState");
  straight.init();
}

void PlaygroundGameState::run()
{
  straight.forward();
  if (ev3_button_is_pressed(RIGHT_BUTTON)) {
    straight.backward();
  }
}

bool PlaygroundGameState::isChanged()
{
}

void PlaygroundGameState::terminate()
{
  msg_f("Stopped.", 1);
  straight.terminate();
  ev3_led_set_color(LED_RED);
}

