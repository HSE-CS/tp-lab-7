//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Predator::~Predator() {
  return;
}

void Predator::attack() {
  Cell* newCell = cell->getOcean()->findPrey(cell);
  if (newCell == nullptr) {
      if (hungerPoints > 0)
          hungerPoints--;
      move();
      return;
  }
  newCell->getObject()->death();
  newCell->setObject(this);
  cell->setObject(nullptr);
  setCell(newCell);
  hungerPoints++;
}

void Predator::breed() {
  Cell* newCell = cell->getOcean()->findEmpty(cell);
  if (newCell == nullptr)
      return;
  Prey* predatorChild = new Predator(newCell);
  newCell->setObject(predatorChild);
  cell->getOcean()->addObject(predatorChild);
}

void Predator::live() {
  if (healthPoints == 0) {
    death();
    return;
  }

  attack();
  if (hungerPoints > 0) {
      if (breedCounter >= breedRate) {
          breedCounter = 0;
          breed();
      } else {
          breedCounter++;
      }
  } else {
    healthPoints--;
  }
}

void Predator::death() {
  cell->getOcean()->addDeleteCandidate(this);
  objType = ObjType::DEAD;
}
