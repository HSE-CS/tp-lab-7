// Copyright 2021 Dev-will-work
#include "Prey.h"

Prey::Prey() {
  this->type = ObjType::PREY;
  this->lifetime = PREY_LIFE;
}

Prey::~Prey() {
}

void Prey::live() {
  if (!this->cell) return;
  Object* new_obj = new Prey;
  Cell* place = this->cell->getAnyNeighbourCell();

  if (place && place->calcObjectsNear(this->getType()) > 1) {  // breeding
    new_obj->setCell(place);
    place->setObject(new_obj);
    this->cell->getOcean()->getStuff().push_front(new_obj);
  } else if (place) {  // move
    this->cell->setObject(nullptr);
    this->cell = place;
    this->cell->setObject(this);
  }

  if (this->lifetime > 0) {
    this->lifetime--;
  } else {
    this->cell->killMe();
  }
}
// object logic

void Prey::print() {
  std::cout << PREY_N;
}
