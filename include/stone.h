// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/common.h"
#include "../include/object.h"
#include "../include/cell.h"

class Stone : public Object{
 public:
    static const unsigned int std_life_time = 1;
    explicit Stone(Cell *c) : Object(c) {
        this->life_time = 1;
    }
    void live() override;
    char getCharacter() override { return '.'; }
    ObjectType getType() override { return ObjectType::STONE;}
};


#endif  // INCLUDE_STONE_H_
