/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

#include "TemplateDeterminationModel.h"
/*
Clock クラスの変更点あり　実機(μsec) シミュレータ(msec) 
https://github.com/ETrobocon/etrobo/wiki/api_ev3rt_on_athrill 
*/
#include "Clock.h"

using namespace ev3api;

class WaitTimeDterminationModel : public TemplateDeterminationModel
{
    Clock clock;

public:
    void init();
    bool determine(uint64_t waitTime);
    void terminate();
};