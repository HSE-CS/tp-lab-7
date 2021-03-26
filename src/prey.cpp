// Copyright 2021 Galex

#include "../include/prey.h"

void Prey::live() {
  this->move();
  this->reproduce();
  this->lifetime++;
  if (this->lifetime > PREY_LIFETIME){
    this->cell->kill();
  }
}
void Prey::move() {
  Cell *newCell = this->cell->getRandNeighbourCell();
  if (newCell) {
    this->cell->setObject(nullptr);
    this->setCell(newCell);
    this->cell->setObject(this);
  }
}
void Prey::reproduce() {
  if (this->lifetime % CREATURE_REPRODUCTION_TIME == 0){
    Cell* cellForChildren = this->cell->getNeighbourCell();
    if (cellForChildren){
      Prey* newPrey = new Prey(cellForChildren);
      cellForChildren->setObject(newPrey);
      this->cell->getOcean()->addObject(newPrey);
    }
  }
}
std::string Prey::getOutput() {
  return "\033[32;42mO\033[0m";
}

