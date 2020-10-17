#pragma once

class TemplateDeterminationModel
{
public:
    virtual void init();
    virtual bool determine();
    virtual void terminate();
};