// Copyright 2021 Egor Buzanov

#include "../include/prey.h"

void Prey::live() {
  ++age;
  if (age <= lifetime) {
    if (age >= reproduction) {
      reproduction += reproduction;
      cell->getOcean()->AddObject(new Prey());
    }
    cell->getOcean()->objectStep(cell);
  } else {
    cell->killMe();
  }
}
