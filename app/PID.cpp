#include "PID.h"

PID::PID(float k_p, float k_i, float k_d)
{
    this->k_p = k_p;
    this->k_i = k_i;
    this->k_d = k_d;
}

PID::~PID()
{
}