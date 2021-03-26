// Copyright 2020 Uskova
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"
#include "Object.h"


class Predator : public Prey {
 private:
  /*int lifeTime;
  int breedTime;*/
  int hungry;
  //ObjType type;

 public:
    explicit Predator(Cell*, ObjType);
    char getObjSym() override;
    void live() override;
    void updateBreedTime();
    void updateHungry();
    void hunting();
    //ObjType getType();
};

#endif  // INCLUDE_PREDATOR_H_
