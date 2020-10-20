#pragma once

#include "TemplateDeterminationModel.h"

class TouchDeterminationModel : public TemplateDeterminationModel
{

public:
    void init();
    bool determine();
    void terminate();
};