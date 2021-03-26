// Copyright 2021 by Sid

#ifndef Stone_h
#define Stone_h
#include "Object.h"

class Stone: public Object {

public:

    Stone(Cell* cell) : Object(cell) {}

    bool live() { return true; }

    char getSymbol() { return STONE_CHAR; }
};


#endif /* Stone_h */
