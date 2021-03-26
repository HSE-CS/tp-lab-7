//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_PREDATOR_H
#define INCLUDE_PREDATOR_H

#include "../include/Object.h"

class Predator : public Object {
 private:
    int lifespan = 0;
    int fullness = 100;
    int step = 0;

 public:
    Predator(Cell* thisCell);
    void live() override;
    void setType() override;
};

#endif  //  INCLUDE_PREDATOR_H
