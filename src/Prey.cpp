// Copyright 2021 Dumarevskaya
#include "Prey.h"
#include "Ocean.h"
#include "Cell.h"
#include <iostream>

void Prey::live() {
  if (lifeTime-- != 0) {
    if (lifeTime % timeToReproduce == 0) {
      reproduce();
    } else {
      move();
    }
  } else {
    cell->killMe();
  }
}

void Prey::move() {
  Cell* newCell = cell->findEmptyAround();
  cell->setObject(nullptr);
  newCell->setObject(this);
  setCell(newCell);
}

void Prey::reproduce() {
  Cell* newCell = cell->findEmptyAround();
  Prey* baby = new Prey(newCell);
  newCell->setObject(this);
  cell->getOcean()->addObject(this);
}

Cell* Prey::getCell() {
  return this->cell;
}
