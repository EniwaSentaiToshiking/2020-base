/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

#include "TemplateDeterminationModel.h"

class TouchDeterminationModel : public TemplateDeterminationModel
{

public:
    void init();
    bool determine();
    void terminate();
};