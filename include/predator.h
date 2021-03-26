// Copyright 2021 Artem Danyaev
#pragma once

#include "../include/object.h"

class Predator : public Object {
 private:
  int reprTime = predatorReprTime;
  int needFoodAfter = predatorNeedFoodAfter;
  int timeInHunger = 0;

 public:
  explicit Predator(Cell* c = nullptr);
  void live();
  Cell* findPrey();
};
