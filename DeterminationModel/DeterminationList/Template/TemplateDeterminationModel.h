/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

class TemplateDeterminationModel
{
public:
    virtual void init();
    virtual bool determine();
    virtual void terminate();
};