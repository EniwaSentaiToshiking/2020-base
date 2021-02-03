/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#include "WaitTimeDterminationModel.h"

void WaitTimeDterminationModel::init()
{
    clock.reset();
}

bool WaitTimeDterminationModel::determine(uint64_t waitTime)
{
    clock.wait(waitTime);
    return true;
}

void WaitTimeDterminationModel::terminate()
{
    clock.reset();
}