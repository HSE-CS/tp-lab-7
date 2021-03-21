// Copyright Baklanov 2021
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "Ocean.h"
#include "Common.h"

class Object;

class Predator : public Object {
 private:
     int hunger;
     bool readyForCatch;

 public:
     Predator(Pair coord, Cell* cell) :
         Object(ObjType::PREDATOR, coord, cell),
         hunger(10), readyForCatch(false) {}
     ~Predator() {}
     Object* Searching(Ocean* ocean);
     friend Ocean;
     void live() override;
};
#endif  // INCLUDE_PREDATOR_H_
