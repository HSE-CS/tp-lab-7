// Copyright 2020 Vadukk

#include "../include/prey.h"

Prey::Prey(Cell* cell) : Object(cell) {
  setTimeOfLive(TIME_PREY);
  this->type = ObjType::PREY;
}

void Prey::live() {
  move();
  time_of_life--;
  if (time_of_life == 0) {
    die();
  } else if (!(time_of_life % 5)) {
    makeChild();
  }
}

char Prey::getSymbol() {
  return PREY_N;
}

void Prey::move() {
  Cell* newCell = cell->moveToCell();
  if (cell->getObject() == nullptr) {
    this->cell->setObject(nullptr);
    this->setCell(nullptr);
    newCell->setObject(this);
    this->cell = newCell;
  }
}

void Prey::makeChild() {
  Cell* newCell = cell->moveToCell();
  if (newCell->getObject() == nullptr) {
    Object* child = new Prey(newCell);
    cell->getOcean()->addObj(child);
    newCell->setObject(child);
  }
}
