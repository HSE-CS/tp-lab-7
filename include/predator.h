// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/common.h"
#include "../include/ocean.h"
#include "../include/prey.h"
#include "../include/object.h"
#include "../include/cell.h"

class Predator : public Prey {
 public:
    static const unsigned int std_life_time = 20;
    Predator(Cell *c, unsigned int lt) : Prey(c, lt) {}
    void live() override;

    Cell *getNextCell();
    void goToCell(Cell *c);

    char getCharacter() override { return 'S'; }
    ObjectType getType() override { return ObjectType::PREDATOR; }
};


#endif  // INCLUDE_PREDATOR_H_
