#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "common.h"
#include "Ocean.h"

class Object;

class Predator : public Object {
 private:
     int hunger;
     bool readyForCatch;

 public:
     Predator(Pair coord, Cell* cell) :
         Object(ObjType::PREDATOR, coord, cell), hunger(10), readyForCatch(false) {}
     ~Predator() {

     };
     Object* Searching(Ocean& ocean);
     friend Ocean;
     void live() override;
};
#endif
