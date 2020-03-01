#include "Lot.h"

#ifndef DETECTER_H
#define DETECTER_H

class Detector {

public:
    virtual bool detect() = 0;
    virtual void init() = 0;
    virtual ~Detector(){};
};

#endif