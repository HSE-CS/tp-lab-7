// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include <string>
#include "../include/stone.h"

class Stone : public Object {
 public:
    Stone();
    ~Stone();
    void live() override;
    void die() override;
    char getSymbol();
 protected:
    char symbol = '*';
};

#endif  // INCLUDE_STONE_H_
