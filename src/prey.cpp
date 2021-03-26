// Copyright 2021 Ryzhova
#include "../include/prey.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Prey::Prey(Cell* cell) : Object(ObjType::PREY, cell) {}

void Prey::live() {
  lifetime++;
  Cell *newCell = findEmpty(cell);
  if (newCell)
    moving(newCell);
  if (lifetime % PREY_BREEDING == 0)
    propagation();
  if (lifetime == PREY_VITALITY)
    cell->killMe();
}

void Prey::moving(Cell* newCell) {
  newCell->setObject(this);
  this->cell->setObject(nullptr);
  this->setCell(newCell);
  this->cell->setObject(this);
}

void Prey::propagation() {
  Cell *newCell = findEmpty(cell);
  Object* child = new Prey(newCell);
  newCell->setObject(child);
  newCell->getOcean()->addObject(child);
}
