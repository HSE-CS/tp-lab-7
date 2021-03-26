//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_PREDATOR_H
#define INCLUDE_PREDATOR_H

#include "../include/Object.h"

class Predator : public Object {
 private:
    int lifespan = 0;
    int hunger = 100;

 public:
    Predator(Cell* thisCell);
    void live() override;
    void setType() override;
};

#endif  //  INCLUDE_PREDATOR_H
