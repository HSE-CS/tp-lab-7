// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#include "../include/predator.h"
#include "../include/ocean.h"
#include "../include/cell.h"

int Predator::getPredatorBreed() const {
  return this->breedCount;
}
void Predator::setPredatorBreed(int val) {
  this->breedCount = val;
}
void Predator::updatePredatorBreed() {
  this->breedCount--;
}

int Predator::getPredatorHealth() const {
  return this->healthCount;
}

void Predator::updatePredatorHealth() {
  this->healthCount--;
}

/* live */
void Predator::live() {
  this->movePredator();
}

void Predator::movePredator() {
  if (this->getPredatorBreed() <= 0) {
    this->PredatorBreed();
  }
  if (this->getPredatorHealth() <= 0) {
    killPredator();
    return;
  }
  updatePredatorHealth();
  Cell *newPlace;
  newPlace = this->cell->huntStart();
  if (newPlace != nullptr) {
    updatePredatorBreed();
    this->healthCount++;
    newPlace->killMe();
  } else {
    newPlace = this->cell->findMove();
    if (newPlace == nullptr) {
      return;
    }
  }
  this->cell->setObject(nullptr);
  newPlace->setObject(this);
  setCell(newPlace);
}

void Predator::PredatorBreed() {
  Cell *newPlace = this->cell->findMove();
  if (newPlace == nullptr) {
    return;
  }
  this->setPredatorBreed(BREED_PREDATOR_TIME);
  auto *childPredator = new Predator
      (ObjType::PREDATOR, newPlace);
  newPlace->setObject(childPredator);
  cell->getOcean()->addObjects(childPredator);
}

void Predator::killPredator() {
  this->cell->killMe();
}



