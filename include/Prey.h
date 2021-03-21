// Copyright Baklanov 2021
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "Cell.h"
#include "Common.h"
#include <list>

class Object;

class Prey: public Object {
 public:
     Prey(Pair coord, Cell* cell) :
         Object(ObjType::PREY, coord, cell) {}
    ~Prey() override;
    void live() override;
};
#endif  // INCLUDE_PREY_H_

