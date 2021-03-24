#ifndef _PREY_H_
#define _PREY_H_

#include "object.h"

class Prey : public Object {
public:
    Prey(Cell* = nullptr);
    virtual void live();
};

#endif