// Copyright 2021 Shirokov Alexander

#include "../include/prey.h"
#include "../include/ocean.h"
#include "../include/common.h"

Prey::Prey(Cell* cell) : Object{cell} {
  this->timeToDie = preyLife;
  this->timeToReproduce = preyReproduction;
  this->setType(ObjType::PREY);
}

void Prey::live() {
  if (this->timeToDie > 0) {
    Cell* tmp = this->cell->findPlace();
    if (tmp != nullptr) {
      this->cell->setObject(nullptr);
      this->cell = tmp;
      this->cell->setObject(this);
    }
    this->timeToDie--;
    this->reproduce();
  } else {
    this->cell->killMe();
  }
}

void Prey::reproduce() {
  if (this->timeToReproduce == 0) {
    Cell* tmp = this->cell->findPlace();
    if (tmp != nullptr) {
      Prey* newPrey = new Prey(tmp);
      tmp->setObject(newPrey);
      tmp->getOcean()->addObject(newPrey);
    }
    this->timeToReproduce = preyReproduction;
  } else {
    this->timeToReproduce--;
  }
}
