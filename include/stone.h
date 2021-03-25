// Copyright 2021 MalininDmitry

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include "object.h"

class Stone : public Object {
 protected:
    ObjType type;
 public:
    explicit Stone(Cell* cell);
    ~Stone() override;
    void live() override;
};

#endif  // INCLUDE_STONE_H_
