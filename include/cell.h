//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_CELL_H
#define INCLUDE_CELL_H

#include "ocean.h"
#include "common.h"
#include "Object.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair coordinates;
    Object* obj;


 public:
};

#endif  //  INCLUDE_CELL_H
