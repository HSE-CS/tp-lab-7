// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
 public:
    explicit Stone(Cell* _cell = nullptr,
                   NATURE _nature = NATURE::STONE,
                   unsigned int _age = 0);
    ~Stone();
};

#endif  //  INCLUDE_STONE_H_
