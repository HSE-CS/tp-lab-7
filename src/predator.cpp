// Copyright 2021 mkhorosh

#include "predator.h"
#include "cell.h"
#include <time.h>
#include "ocean.h"
#include <cstdlib>

Predator::Predator(ObjType type, Cell *cell) : Object(type, cell) {
  hunger_timer = 0;
  this->type = type;
  this->cell = cell;
}

void Predator::live() {
  // move
  Cell *newCell = cell->makeCell();
  if (cell->getObject() == nullptr) {
    cell->setObject(nullptr);
    this->setCell(nullptr);
    newCell->setObject(this);
    cell = newCell;
  }
  hunger_timer++;
  if (hunger_timer > 10) {
    death();
  } else if (isAlive()) {
    // eat
    Cell *prey = cell->makeCell();
    if (prey->getObject() != nullptr && prey->getObject()->isAlive()) {
      prey->getObject()->death();
      hunger_timer = 0;
    }
  }
}
Predator::~Predator() {

}
