/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

class TemplateEv3State
{
public:
    void init();
    void run();
    bool isFinished();
    void terminate();
}