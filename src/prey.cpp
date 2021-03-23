// Copyright by Egor Bodrov 2021

#include "prey.h"
#include "ocean.h"
#include "common.h"

Prey::Prey(Cell* cell)
    : Object{cell}, timeToDie{PreyLife}, timeToReproduce{PreyReproduce} {
  this->setType(ObjectType::PREY);
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
    this->spawn();
  } else {
    this->cell->killMe();
  }
}

void Prey::spawn() {
  if (this->timeToReproduce == 0) {
    Cell* tmp = this->cell->findPlace();
    if (tmp != nullptr) {
      Prey* n_prey = new Prey(tmp);
      tmp->setObject(n_prey);
      tmp->getOcean()->addObject(n_prey);
    }
    this->timeToReproduce = PreyReproduce;
  } else {
    this->timeToReproduce--;
  }
}
