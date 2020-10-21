#pragma once

class TemplateBehaviorModel
{
public:
    virtual void init();
    virtual void run(int pwm);
    virtual void terminate();

protected:
    int runActionState;
};