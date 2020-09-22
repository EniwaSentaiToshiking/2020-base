#include "PlaygroundGame.h"

PlaygroundGame::PlaygroundGame()
{
}

void PlaygroundGame::init()
{
  init_f("PlaygroundGame");
  straight.init();
}

void PlaygroundGame::terminate()
{
  msg_f("Stopped.", 1);
  straight.terminate();
  ev3_led_set_color(LED_RED);
}

void PlaygroundGame::run()
{
  straight.forward();
  if (ev3_button_is_pressed(RIGHT_BUTTON)) {
    straight.backward();
  }
}
