// Copyright 2021 Galex

#include "../include/predator.h"

void Predator::live() {
  this->move();
  this->reproduce();
  this->lifetime++;
  if (this->lifetime > PREDATOR_LIFETIME || this->satiety <= 0) {
    this->cell->kill();
  }
}
void Predator::reproduce() {
  if (this->satiety == PREDATOR_MAX_SATIETY) {
    Cell *cellForChildren = this->cell->getNeighbourCell();
    if (cellForChildren) {
      Predator *newPredator = new Predator(cellForChildren);
      cellForChildren->setObject(newPredator);
      this->cell->getOcean()->addObject(newPredator);
    }
  }
}
void Predator::move() {
  if (this->lifetime % 4 == 0) {
    this->satiety--;
  }
  Cell *newCell = this->cell->getRandPreyNeighbourCell();
  if (newCell && !newCell->isFree() &&
      newCell->getObject()->getType() == TYPE::PREY) {
    newCell->kill();
    this->satiety++;
    this->setCell(newCell);
    newCell->setObject(this);
  }
  if (this->satiety > PREDATOR_MAX_SATIETY) {
    this->satiety = PREDATOR_MAX_SATIETY;
  }
}
std::string Predator::getOutput() {
  return "\033[31;41mO\033[0m";
}

