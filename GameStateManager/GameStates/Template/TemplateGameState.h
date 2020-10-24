#pragma once

#include "DebugUtil.h"

class TemplateGameState
{
    DebugUtil d;
    
public:
    virtual void init();
    virtual void createRunSectionL();
    virtual void createRunSectionR();
    virtual void run();
    virtual bool isFinished();
    virtual void terminate();
};