#pragma once

#include "util.h"
#include "Straight.h"

using namespace ev3api;

class PlaygroundGame
{
public:
  PlaygroundGame();
  void run();
  void init();
  void terminate();

private:
  Straight straight;
};
