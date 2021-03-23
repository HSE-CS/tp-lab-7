// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/common.h"
#include "../include/object.h"
#include "../include/cell.h"

class Prey : public Object {
 public:
    static const unsigned int std_life_time = 10;
    Prey(Cell *c, unsigned int lt) : Object(c) {
        this->life_time = lt;
    }
    void live() override;

    virtual Cell *getNextCell();
    virtual void goToCell(Cell *c);
    ObjectType getType() override { return ObjectType::PREY; }
    char getCharacter() override { return 'f'; }
};


#endif  // INCLUDE_PREY_H_
