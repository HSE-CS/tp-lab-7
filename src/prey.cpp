// Copyright 2021 Elise
#include "../include/prey.h"

#include "../include/object.h"
#include "../include/common.h"
#include "../include/ocean.h"
#include "../include/cell.h"


Prey::Prey(Cell* cell) : Object(cell) {
  this->type_object = PREY_N;
  this->time = 10;
}

void Prey::live() {
  if (time > 0) {
    sail();
    if (time % 2 == 0) {
      this->babies();
    }
    time--;
  } else {
    this->cell->killMe();
  }
}

void Prey::sail() {
  Cell* new_cell = cell->newCell();
  if (new_cell) {
    this->cell->setObject(nullptr);
    this->cell = new_cell;
    this->cell->setObject(this);
  }
}

void Prey::babies() {
  Cell* new_cell = cell->newCell();
  if (new_cell) {
    Prey* new_prey = new Prey(new_cell);
    new_cell->setObject(new_prey);
    new_cell->getOcean()->addObject(new_prey);
  }
}
