// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#include "../include/prey.h"
#include "../include/cell.h"
#include "../include/ocean.h"

int Prey::getBreedCount() const {
  return this->breedCount;
}
void Prey::setBreedCount(int val) {
  this->breedCount = val;
}
void Prey::updateBreedCount() {
  this->breedCount--;
}

int Prey::getHealth() const {
  return this->healthCount;
}

void Prey::updateHealth() {
  this->healthCount--;
}

void Prey::live() {
  this->movePrey();
}

void Prey::movePrey() {
  if (this->getBreedCount() <= 0) {
    this->breedPrey();
  }
  if (this->getHealth() <= 0) {
    killPrey();
    return;
  }
  this->updateBreedCount();
  this->updateHealth();
  Cell *newPlace = this->cell->findMove();
  if (newPlace == nullptr) {
    return;
  }
  this->cell->setObject(nullptr);
  newPlace->setObject(this);
  setCell(newPlace);
}

void Prey::breedPrey() {
  Cell *newPlace = this->cell->findMove();
  if (newPlace == nullptr) {
    return;
  }
  this->setBreedCount(BREED_PREY_TIME);
  Prey *babyPrey = new Prey(ObjType::PREY, newPlace);
  newPlace->setObject(babyPrey);
  cell->getOcean()->addObjects(babyPrey);
}

void Prey::killPrey() {
  this->cell->killMe();
}
