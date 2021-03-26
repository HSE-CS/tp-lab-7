// Copyright 2021 Kuznetsov Mikhail
#include "prey.h"
#include "ocean.h"
#include "cell.h"



Prey::Prey(Cell * _cell,
           NATURE _nature,
           unsigned int _age) :
  Object(_cell, _nature, _age){
}

Prey::~Prey() {
}

void Prey::live() {
  if (age < FEATURES::longevity[nature]) {
    age++;
    if (cell->getTemperature() > FEATURES::maxTemperature[nature] ||
      cell->getTemperature() < FEATURES::minTemperature[nature]) {
      cell->getOcean()->deleteObject(cell);
      return;
    }
    if (!(age % FEATURES::breedingTime[nature])) {
      this->breed();
    }
    this->swim();
  }
}

void Prey::swim() {
  auto area = cell->getArea();
  auto ocean = cell->getOcean();
  for (auto p: area) {
    auto newCell = ocean->getCell(p.first, p.second);
    auto object = newCell->getObject();
    if(object == nullptr) {
        newCell->setObject(this);
        cell->setObject(nullptr);
        break;
    }
  }
}

void Prey::breed() {
  auto area = cell->getArea();
  auto ocean = cell->getOcean();
  for (auto p: area) {
    auto newCell = ocean->getCell(p.first, p.second);
    auto object = newCell->getObject();
    if(object == nullptr) {
      Prey* prey = new Prey(newCell, NATURE::PREY, 0);
      ocean->addObject(prey);
      newCell->setObject(prey);
      break;
    }
  }
}

