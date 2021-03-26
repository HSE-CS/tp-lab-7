// Copyright 2020 Uskova
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "stone.h"
#include "Object.h"

class Prey : public Stone {
 //private:
 // ObjType type;
 protected:
  int lifeTime;
  int breedTime;

 public:
  explicit Prey(Cell*, ObjType);
  char getObjSym() override;
  void live() override;
  void updateLifeTime();
  void updateBreedTime();
  void breeding();
  void move();
  int getLifeTime();
  int getBreedTime();
  //ObjType getType();
  void die();
};

#endif  // INCLUDE_PREY_H_
