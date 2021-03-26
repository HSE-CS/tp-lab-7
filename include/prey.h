//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_PREY_H
#define INCLUDE_PREY_H

#include "../include/Object.h"

class Prey : public Object {
 private:
    int lifespan = 0;
    int steps = 0;
    bool cooldown = false;

 public:
    Prey(Cell* thisCell);
    void live() override;
    void setType() override;
};

#endif  //  INCLUDE_PREY_H
