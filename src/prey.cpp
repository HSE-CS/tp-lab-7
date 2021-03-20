//// Copyright 2021 Ozhiganova Polina
#include "prey.h"
#include "cell.h"
#include "ocean.h"

/* breed */
int Prey::getBreedCount() const {
  return this->breedCount;
}
void Prey::setBreedCount(int val) {
  this->breedCount = val;
}
void Prey::updateBreedCount() {
  this->breedCount--;
}

/* health */
int Prey::getHealth() const {
  return this->healthCount;
}

void Prey::setHealth(int val) {
  this->healthCount = val;
}

void Prey::updateHealth() {
  this->healthCount--;
}

void Prey::live() {
  this->movePrey();
}

/* move */
void Prey::movePrey() {
  //  time to breed
  if (this->getBreedCount() <= 0) {
    this->breedPrey();
  }
  //  time to die
  if (this->getHealth() <= 0) {
    killPrey();
    return;
  }
  //  move
  this->updateBreedCount();
  this->updateHealth();
  Cell *newPlace = this->cell->findPlace();
  if (newPlace == nullptr) {
    return;
  }
  this->cell->setObject(nullptr);
  newPlace->setObject(this);
  setCell(newPlace);
}

/* breed prey */
void Prey::breedPrey() {
  Cell *newPlace = this->cell->findPlace();  //  for parent prey
  if (newPlace == nullptr) {
    return;
  }
  this->setBreedCount(PREY_BREED_PERIOD);
  Prey *babyPrey = new Prey(ObjType::PREY, newPlace);
  newPlace->setObject(babyPrey);
  cell->getOcean()->addObjects(babyPrey);
}

/* kill prey */
void Prey::killPrey() {
  this->cell->killMe();
}
