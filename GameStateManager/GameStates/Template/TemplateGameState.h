/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
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