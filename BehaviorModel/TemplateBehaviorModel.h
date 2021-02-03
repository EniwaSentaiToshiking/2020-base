/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#pragma once

class TemplateBehaviorModel
{
public:
    virtual void init();
    virtual void run(int pwm);
    virtual void terminate();
};