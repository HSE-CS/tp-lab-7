// Copyright 2021 MalininDmitry

#ifndef _STONE_H_
#define _STONE_H_
#include "object.h"
#include "cell.h"
#include "ocean.h"

class Stone : public Object {
 protected:
    ObjType type;
 public:
    explicit Stone(Cell* cell);
    ~Stone() override;
    void live() override;
};

#endif
