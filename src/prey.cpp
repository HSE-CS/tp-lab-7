// Copyright 2020 Uskova

#include "prey.h"
#include "cell.h"


Prey::Prey(Cell* c, ObjType objType) : Stone(c, objType) {
    this->lifeTime = PREY_LIFETIME;
    this->breedTime = PREY_BREEDING;
}

char Prey::getObjSym() {
    return PREY_N;
}

/*ObjType Prey::getType() {
    return this->type;
}*/

void Prey::updateLifeTime() {
    (this->lifeTime)--;
}

void Prey::updateBreedTime() {
  if (this->breedTime <= 0) {
     this->breedTime = PREY_BREEDING;
  } else {
    (this->breedTime)--;
  }
}

void Prey::breeding() {
    Cell* freeCell = this->cell->freePlace();
  if (freeCell != nullptr) {
     Prey* child = new Prey(freeCell, ObjType::PREY);
     freeCell->setObject(child);
     this->cell->getOcean()->addObject(child);
  }
}

void Prey::move() {
  Cell* freeCell = this->cell->freePlace();
  if (freeCell != nullptr) {
    this->cell->setObject(nullptr);
    freeCell->setObject(this);
    this->setCell(freeCell);
  }
}

void Prey::die() {
    this->cell->getOcean()->inDeleteList(this);
}

void Prey::live() {
  if (this->lifeTime <= 0) {
      die();
  } else {
    if (this->breedTime <= 0) {
      breeding();
    }
    move();
    updateLifeTime();
    updateBreedTime();
  }
}

int Prey::getLifeTime() {
    return this->lifeTime;
}


int Prey::getBreedTime() {
    return this->breedTime;
}
