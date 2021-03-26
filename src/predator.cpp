// Copyright 2021 Kuznetsov Mikhail
#include "predator.h"
#include "ocean.h"
#include "cell.h"


Predator::Predator(Cell * _cell,
                  NATURE _nature,
                  unsigned int _age) :
  Prey(_cell, _nature, _age){
}

Predator::~Predator() {
}

void Predator::live() {
  if (age < FEATURES::longevity[nature]) {
    age++;
    if (cell->getTemperature() > FEATURES::maxTemperature[nature] ||
      cell->getTemperature() < FEATURES::minTemperature[nature]) {
      cell->getOcean()->deleteObject(cell);
      return;
    }
    if (!(age % FEATURES::eatTime[nature])) {
      if (!this->eat()) {
        cell->getOcean()->deleteObject(cell);
        return;
      }
    }
    if (!(age % FEATURES::breedingTime[nature])) {
      this->breed();
    }
    this->swim();
  }
}

bool Predator::eat() {
  auto area = cell->getArea();
  auto ocean = cell->getOcean();
  for (auto p: area) {
    auto newCell = ocean->getCell(p.first, p.second);
    auto object = newCell->getObject();
    if(nullptr != object &&
       NATURE::PREY == object->getNature()) {
      ocean->deleteObject(newCell);
      return true;
    }
  }
  return false;
}



