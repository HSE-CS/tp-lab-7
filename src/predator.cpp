//// Copyright 2021 Ozhiganova Polina
#include "../include/predator.h"
#include "../include/ocean.h"
#include "../include/cell.h"

/* breed */
int Predator::getBreedPredator() const {
  return this->breedCount;
}
void Predator::setBreedPredator(int val) {
  this->breedCount = val;
}
void Predator::updateBreedPredator() {
  this->breedCount--;
}

/* health */
int Predator::getHealthPredator() const {
  return this->healthCount;
}

void Predator::setHealthPredator(int val) {
  this->healthCount = val;
}

void Predator::updateHealthPredator() {
  this->healthCount--;
}

/* live */
void Predator::live() {
  this->movePredator();
}

void Predator::movePredator() {
  // time to breed
  if (this->getBreedPredator() <= 0) {  // time to breed
    this->breedPredator();
  }
  //  time to die
  if (this->getHealthPredator() <= 0) {
    killPredator();
    return;
  }
  //  move
  updateHealthPredator();
  Cell *newPlace;
  newPlace = this->cell->goHunt();
  if (newPlace != nullptr) {
    updateBreedPredator();
    this->healthCount++;
    newPlace->killMe();
  } else {
    newPlace = this->cell->findPlace();
    if (newPlace == nullptr) {
      return;
    }
  }
  this->cell->setObject(nullptr);
  newPlace->setObject(this);
  setCell(newPlace);
}

void Predator::breedPredator() {
  Cell *newPlace = this->cell->findPlace();
  if (newPlace == nullptr) {
    return;
  }
  this->setBreedPredator(PREDATOR_BREED_PERIOD);
  Predator *babyPredator = new Predator
      (ObjType::PREDATOR, newPlace);
  newPlace->setObject(babyPredator);
  cell->getOcean()->addObjects(babyPredator);
}

/* kill prey */
void Predator::killPredator() {
  this->cell->killMe();
}



