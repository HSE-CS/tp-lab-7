// Copyright 2021 Ryzhova
#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Predator::Predator(Cell* cell) : Object(ObjType::PREDATOR, cell) {}

void Predator::live() {
  lifetime++;
  Cell *newCell = findPrey(cell);
  if (newCell)
    murder(newCell);
  else
    newCell = findEmpty(cell);
  if (newCell)
    moving(newCell);
  if (lifetime % PREDATOR_BREEDING == 0 && victimCounter / lifetime > 0.2)
    propagation();
  if (lifetime == PREDATOR_VITALITY || victimCounter / lifetime < 0.2)
    cell->killMe();
}

void Predator::propagation() {
  Cell *newCell = findEmpty(cell);
  Object* child = new Predator(newCell);
  newCell->setObject(child);
  newCell->getOcean()->addObject(child);
}

void Predator::moving(Cell* newCell) {
  newCell->setObject(this);
  this->cell->setObject(nullptr);
  this->setCell(newCell);
  this->cell->setObject(this);
}

void Predator::murder(Cell* newCell) {
  newCell->killMe();
  victimCounter++;
}
