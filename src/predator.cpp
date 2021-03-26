// Copyright 2020 Uskova

#include "predator.h"
#include "cell.h"
#include "ocean.h"

Predator::Predator(Cell* c, ObjType objType) : Prey(c, objType) {
  this->lifeTime = PREDATOR_LIFETIME;
  this->breedTime = PREDATOR_BREEDING;
  this->hungry = HUNGRY;
}

char Predator::getObjSym() {
    return PREDATOR_N;
}

/*ObjType Predator::getType() {
    return this->type;
}*/

void Predator::live() {
  if (this->lifeTime <= 0 || this->hungry <= 0) {
    die();
  } else {
    if (this->breedTime <= 0 && this->hungry >= 1) {
        breeding();
    }
    if (this->hungry <= 4) {
        hunting();
    } else {
        updateHungry();
    }
    move();
    updateLifeTime();
    updateBreedTime();
  }
}

void Predator::updateBreedTime() {
  if (this->breedTime <= 0) {
    this->breedTime = PREDATOR_BREEDING;
  } else {
    (this->breedTime)--;
  }
}


void Predator::updateHungry() {
    (this->hungry)--;
}


void Predator::hunting() {
  Cell* prey = this->cell->forHunting();
  if (prey != nullptr) {
    //prey->killMe();
    this->cell->getOcean()->inDeleteList(prey->getObject());
    this->cell->setObject(nullptr);
    prey->setObject(this);
    this->setCell(prey);
  } else {
    updateHungry();
  }
}
