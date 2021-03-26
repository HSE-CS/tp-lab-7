// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include "../include/stone.h"

class Prey : public Stone {
 private:
  ObjType ot;
  int breedCount;
  int healthCount;
 public:
  explicit Prey(ObjType type, Cell *cell) :
      Stone(type, cell),
      ot(type),
      breedCount(BREED_PREY_TIME),
      healthCount(LIFE_PREY_TIME) {}
  void live() override;
  void movePrey();
  [[nodiscard]] int getHealth() const;
  void updateHealth();
  void breedPrey();
  void killPrey();
  [[nodiscard]] int getBreedCount() const;
  void setBreedCount(int val);
  void updateBreedCount();
};

#endif  //  INCLUDE_PREY_H_
