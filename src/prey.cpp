#include "prey.h"

#include <iostream>

Prey::Prey(Cell* cell) : Object(cell) {
  this->livetime = LTPrey;
  this->type = ObjType::PREY;
}

void Prey::live() {
  move();
  if (livetime < LTPrey / 2) copulation();
  livetime--;
}

char Prey::getSymbol() { return PREY_N; }

void Prey::move() {
  Cell* newCell = cell->FREE();
  if (newCell) {
    this->getCell()->Moving();
    newCell->setObject(this);
    this->cell = newCell;
  }
}

void Prey::copulation() {
  Cell* newCell = cell->FREE();
  if (newCell) {
    Object* child = new Prey(newCell);
    newCell->setObject(child);
    cell->getOcean()->AddStuff(child);
  }
}
