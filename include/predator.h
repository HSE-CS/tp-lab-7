#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "object.h"

class Predator : public Object {
public:
    Predator(Cell* = nullptr);
    virtual void live();
};

#endif
