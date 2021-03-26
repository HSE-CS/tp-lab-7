// Copyright 2021 Shirokov Alexander

#include "../include/coral.h"
#include "../include/ocean.h"
#include "../include/common.h"

Coral::Coral(Cell* cell) : Object{ cell } {
  this->timeToDie = coralLife;
  this->timeToReproduce = coralReproduction;
  this->setType(ObjType::CORAL);
}

void Coral::live() {
  if (this->timeToDie == 0) {
    this->cell->killMe();
  } else {
    reproduce();
  }
}

void Coral::reproduce() {
  if (this->timeToReproduce == 0) {
    Cell* tmp = this->cell->findPlace();
    if (tmp != nullptr) {
      Coral* newCoral = new Coral(tmp);
      tmp->setObject(newCoral);
      tmp->getOcean()->addObject(newCoral);
    }
    this->timeToReproduce = coralReproduction;
  }
  else {
    this->timeToReproduce--;
  }
}
