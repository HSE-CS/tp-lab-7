// Copyright 2021 Shirokov Alexander

#include "../include/predator.h"
#include "../include/cell.h"

Predator::Predator(Cell* cell) : Prey{ cell }, eaten{ 0 } {
  this->setType(ObjType::PREDATOR);
  this->timeToDie = predatorLife;
  this->timeToReproduce = predatorReproduction;
}

void Predator::live() {
  if (this->timeToDie > 0) {
    Cell* tmp = this->cell->findPrey();
    if (tmp != nullptr) {
      this->eaten += 1;
      tmp->killMe();
      this->cell->setObject(nullptr);
      this->cell = tmp;
      this->cell->setObject(this);
      this->timeToDie += 1;
    } else {
      tmp = this->cell->findPlace();
      if (tmp != nullptr) {
        this->cell->setObject(nullptr);
        this->cell = tmp;
        this->cell->setObject(this);
      }
    }
    this->timeToDie--;
    this->reproduce();
  } else {
    this->cell->killMe();
  }
}

void Predator::reproduce() {
  if (this->timeToReproduce == 0 && this->eaten >= predatorUpgrade) {
    Cell* tmp = this->cell->findPlace();
    if (tmp != nullptr) {
      Predator* newPred = new Predator(tmp);
      tmp->setObject(newPred);
      tmp->getOcean()->addObject(newPred);
    }
    this->timeToReproduce = preyReproduction;
    this->eaten -= predatorUpgrade;
  } else {
    this->timeToReproduce--;
  }
}
