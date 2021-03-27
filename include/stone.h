// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
public:
    explicit Stone(Cell* cell,
                   ObjType type = ObjType::STONE)
    : Object(type, cell) {}
    ~Stone();
    virtual void live();
};


#endif  // INCLUDE_STONE_H_
