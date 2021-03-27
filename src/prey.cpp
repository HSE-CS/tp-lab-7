// Copyright 2021 mkhorosh

#include "../include/prey.h"
#include "../include/cell.h"

Prey::Prey(ObjType type, Cell *cell) : Object(type, cell) {
  this->type = type;
  this->cell = cell;
  life_timer = 0;
}

Prey::~Prey() {
}
void Prey::live() {
  // move
  Cell *newCell = cell->makeCell();
  if (cell->getObject() == nullptr) {
    cell->setObject(nullptr);
    this->setCell(nullptr);
    newCell->setObject(this);
    cell = newCell;
  }
  life_timer++;
  if (life_timer > 6) {
    death();
  } else if (life_timer == 5) {
    // reproduction
    Cell *newCell = cell->makeCell();
    if (newCell->getObject() == nullptr) {
      Object *small_prey = new Prey(ObjType::PREY, newCell);
      cell->getOcean()->push(small_prey);
      newCell->setObject(small_prey);
    }
  }
}
