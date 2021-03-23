// Copyright by Egor Bodrov 2021

#include "predator.h"
#include "cell.h"

Predator::Predator(Cell* cell) : Prey{cell}, eaten {0} {
  this->setType(ObjectType::PREDATOR);
  this->timeToDie = PredLife;
  this->timeToReproduce = PredReproduce;
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
    this->spawn();
  } else {
    this->cell->killMe();
  }
}

void Predator::spawn() {
  if (this->timeToReproduce == 0 && this->eaten >= PredUpgrade) {
    Cell* tmp = this->cell->findPlace();
    if (tmp != nullptr) {
      Predator* n_pred = new Predator(tmp);
      tmp->setObject(n_pred);
      tmp->getOcean()->addObject(n_pred);
    }
    this->timeToReproduce = PreyReproduce;
    this->eaten -= PredUpgrade;
  } else {
    this->timeToReproduce--;
  }
}
