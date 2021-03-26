// copyright 2021 Victor Shatilov

#ifndef INCLUDE_PREDATOR_H
#define INCLUDE_PREDATOR_H

#include "common.h"

class predator : public Object {
 public:
    predator(int x, int y, int energy = startPredatorEnergy,
             int type = PREDATOR, Cell *cell = nullptr);

    virtual void live();

    virtual Object *divide();

    virtual char getFiller();
};


#endif  // INCLUDE_PREDATOR_H
