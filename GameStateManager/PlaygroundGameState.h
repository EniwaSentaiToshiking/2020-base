#pragma once

#include "util.h"
#include "Straight.h"

using namespace ev3api;

class PlaygroundGameState
{
public:
  PlaygroundGameState();
  void init();
  void run();
  bool isChanged();
  void terminate();

private:
  Straight straight;
};
