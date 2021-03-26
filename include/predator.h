// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include "../include/prey.h"

class Predator : public Prey {
 public:
  explicit Predator(ObjType type, Cell *cell) :
      Prey(type, cell),
      ot(type),
      breedCount(BREED_PREDATOR_TIME),
      healthCount(LIFE_PREDATOR_TIME) {}
  void live() override;
  void updatePredatorHealth();
  void PredatorBreed();
  void killPredator();
  void movePredator();
  [[nodiscard]] int getPredatorBreed() const;
  void setPredatorBreed(int val);
  void updatePredatorBreed();
  [[nodiscard]] int getPredatorHealth() const;


 private:
  ObjType ot;
  int breedCount;
  int healthCount;
};

#endif  //  INCLUDE_PREDATOR_H_
