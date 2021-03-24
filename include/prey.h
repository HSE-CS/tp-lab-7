//  Copyright © 2021 Ksuvot
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "Cell.h"
#include "Common.h"
#include <list>

class Object;

class Prey: public Object {
 public:
     Prey(Pair pair, Cell* cell) :
         Object(ObjType::PREY, pair, cell) {}
    void live() override;
    ~Prey() override = default;
};
#endif  // INCLUDE_PREY_H_

