// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include <string>
#include "stone.h"

class Stone : public Object {
protected:
    char symbol = '*';
public:
    Stone();
    ~Stone();
    void live() override;
    void die() override;
    char getSymbol();
};

#endif  // INCLUDE_STONE_H_
