// Copyright Baklanov 2021
#ifndef _PREY_H_
#define _PREY_H_

#include "common.h"
#include "Cell.h"
#include <list>

class Object;

class Prey: public Object {
 public:
     Prey(Pair coord, Cell* cell) :
         Object(ObjType::PREY, coord, cell) {}
    ~Prey() override;
    void live() override;
};
#endif

