// copyright 2021 Victor Shatilov

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/common.h"

class prey : public Object {
 public:
    prey(int x, int y, int energy = startPreyEnergy,
         int type = PREY, Cell *cell = nullptr);

    virtual void live();

    virtual Object *divide();

    virtual char getFiller();
};


#endif  // INCLUDE_PREY_H_
