// Copyright 2021 Egor Trukhin
#include "predator.h"

#include "cell.h"

Predator::Predator(Cell* cell) : Object(cell) {
  this->type = object_t::PREDATOR;
  this->isAlive = true;
  this->isHungry = true;
  this->health = OBJECT_PREDATOR_HEALTH;
  this->stamina = OBJECT_PREDATOR_STAMINA;
}

void Predator::move() {
  if (!this->isAlive) return;

  Cell* moveFrom = this->cell;
  Cell* moveTo = this->cell->findNeighbourCell(NONE);
  if (moveTo == nullptr) return;
  this->cell = moveTo;
  moveTo->setObject(this);
  moveFrom->setObject(nullptr);
}

void Predator::reproduce() {
  if (!this->isAlive) return;
  if (this->isHungry) return;

  // Try to find a cell with a predator nearby
  if (this->cell->findNeighbourCell(PREDATOR) == nullptr) return;

  Cell* target = this->cell->findNeighbourCell(NONE);
  if (target == nullptr) return;
  target->declareBirth(new Predator());
  this->isHungry = true;
}

void Predator::eat() {
  if (!this->isAlive) return;

  // Try to find a cell with a pray nearby
  Cell* prey = this->cell->findNeighbourCell(PREY);
  if (prey == nullptr) return;

  prey->declareDeath();
  this->isHungry = false;
}

void Predator::live() {
  if (this->cell == nullptr) return;

  if (!isAlive || health == 0) {
    this->isAlive = false;
    this->cell->declareDeath();
    return;
  }

  eat();
  reproduce();
  move();
  --health;
}
