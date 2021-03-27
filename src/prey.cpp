// Copyright 2021 Lab_7 TiNa
#include "prey.h"
#include "common.h"
#include "ocean.h"

Prey::Prey(Cell* cell) : Object(cell) {
  type = PREY;
  time_of_life = 17;
}

void Prey::live() {
  if (time_of_life > 0) {
      Cell* prC = cell->find();
      if (prC) {
        cell->setObject(nullptr);
        cell = prC;
        cell->setObject(this);
      }
    reproduction();
    time_of_life--;
  } else {
    cell->killMe();
  }
}

void Prey::reproduction() {
  Cell* prC = cell->find();
  if (prC) {
    Prey* pr = new Prey(prC);
    prC->setObject(pr);
    prC->getOcean()->addObjects(pr);
  }
}
