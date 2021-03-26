// Copyright TimurZaytsev 2021
#include "../include/prey.h"

#include <iostream>

#include "../include/cell.h"
#include "../include/ocean.h"
Prey::Prey(Cell* newCell) {
  this->ReproductionTime = std::rand() % 3 + 4;
  this->reproduct = 0;
  this->cell = newCell;
  this->type = ObjType::PREY;
  this->LiveTime = std::rand() % 10 + 9;
}
void Prey::live() {
  if (this->LiveTime) {
    if (this->reproduct == this->ReproductionTime) {
      Cell* newCell{this->cell->getNeighbour()};
      if (newCell && !newCell->getObj()) {
        this->cell->addObj(this->type, newCell);
        this->reproduct = 0;
      }
    } else {
      Cell* newCell{this->cell->getNeighbour()};
      if (newCell && !newCell->getObj()) {
        this->cell->setObj(nullptr);
        this->set(newCell);
        this->cell->setObj(this);
      }
    }
    this->LiveTime--;
    this->reproduct++;
  } else {
    this->cell->setObj(nullptr);
    this->set(nullptr);
  }
}
