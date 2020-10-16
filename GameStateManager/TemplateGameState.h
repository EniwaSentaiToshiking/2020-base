#pragma once

#include "DebugUtil.h"

class TemplateGameState
{
    DebugUtil d;
    
public:
    virtual void init();
    virtual void run();
    virtual bool isFinished();
    virtual void terminate();
};