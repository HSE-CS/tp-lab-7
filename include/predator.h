//  Copyright © 2021 Ksuvot
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "Ocean.h"
#include "Common.h"

class Object;

class Predator : public Object {
 private:
     int eat;
     bool eating;

 public:
     Predator(Pair pair, Cell* cell) :
         Object(ObjType::PREDATOR, pair, cell),
         eat(10), eating(false) {}
         ~Predator() override = default;
     friend Ocean;
     void live() override;
     Object* Searching(Ocean* ocean);
};
#endif  // INCLUDE_PREDATOR_H_
