// Copyright 2021 Egor Trukhin
#include "prey.h"

#include "cell.h"

Prey::Prey(Cell* cell) : Object(cell) {
  this->type = object_t::PREY;
  this->isAlive = true;
  this->health = OBJECT_PREY_HEALTH;
  this->stamina = OBJECT_PREY_STAMINA;
}

void Prey::move() {
  if (!this->isAlive) return;

  Cell* moveFrom = this->cell;
  Cell* moveTo = this->cell->findNeighbourCell(NONE);
  if (moveTo == nullptr) return;
  this->cell = moveTo;
  moveTo->setObject(this);
  moveFrom->setObject(nullptr);
}

void Prey::reproduce() {
  if (!this->isAlive) return;

  // Try to find a cell with a prey nearby
  if (this->cell->findNeighbourCell(PREY) == nullptr) return;

  Cell* target = this->cell->findNeighbourCell(NONE);
  if (target == nullptr) return;
  target->declareBirth(new Prey());
}

void Prey::live() {
  if (this->cell == nullptr) return;

  if (!isAlive || health == 0) {
    this->isAlive = false;
    this->cell->declareDeath();
    return;
  }

  reproduce();
  move();
  --health;
}
