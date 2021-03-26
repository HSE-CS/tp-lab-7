// Copyright TimurZaytsev 2021
#include "predator.h"

#include <iostream>

#include "cell.h"
Predator::Predator(Cell* newCell) {
  this->cell = newCell;
  this->reproduct = 0;
  this->LiveTime = std::rand() % 10 + 40;
  this->ReproductionTime = std::rand() % 10 + 7;
  this->wellFed = this->fullofEat;
  this->type = ObjType::PREDATOR;
}

void Predator::live() {
  if (this->LiveTime && this->wellFed) {
    if (this->reproduct >= this->ReproductionTime &&
        this->wellFed == this->fullofEat) {
      Cell* newCell{this->cell->getNeighbour()};
      if (newCell && !newCell->getObj()) {
        this->cell->addObj(this->type, newCell);
        this->reproduct = 0;
        this->wellFed -= 2;
      }
    } else {
      Cell* newCell{
          this->cell->getNeighbour(this->wellFed <= this->fullofEat)};
      if (newCell) {
        this->cell->setObj(nullptr);
        if (newCell->getObj()) {
          newCell->getObj()->set(nullptr);
          this->wellFed += 5;
        }
        this->set(newCell);
        this->cell->setObj(this);
      }
    }
    this->wellFed--;
    this->LiveTime--;
    this->reproduct++;
  } else {
    this->cell->setObj(nullptr);
    this->set(nullptr);
  }
}
