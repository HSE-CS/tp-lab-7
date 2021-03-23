// Copyright 2021 Dev-will-work
#include "include/predator.h"
#include "include/cell.h"

Predator::Predator() {
  this->type = ObjType::PREDATOR;
  this->lifetime = PREDATOR_LIFE;
}

Predator::~Predator() {
}

void Predator::live() {
  if (!this->cell) return;
  Pair coord = this->cell->getCoord();
  Object* new_obj = new Predator;

  // |1|4|6|
  // |2|X|7|
  // |3|5|8|
  ObjType wanted = ObjType::PREY;

  Cell* place = this->cell->getAnyNeighbourCell(&wanted);

  if (place && place->getObject() && place->getObject()->getType() == wanted &&
              place->calcObjectsNear(this->getType()) > 1) {  // breeding
    this->starvingLevel = 0;
    place->killMe();
    new_obj->setCell(place);
    place->setObject(new_obj);
    this->cell->getOcean()->getStuff().push_front(new_obj);
  } else if (place && place->getObject() &&
            place->getObject()->getType() == wanted) {  // eat
    this->starvingLevel = 0;
    place->killMe();
    this->cell->setObject(nullptr);
    this->cell = place;
    this->cell->setObject(this);
  } else if (place) {  // move
    this->cell->setObject(nullptr);
    this->cell = place;
    this->cell->setObject(this);
  }

  if (this->lifetime <= 0 || this->starvingLevel >= STARVING) {
    this->cell->killMe();
  } else if (this->lifetime > 0) {
    this->lifetime--;
  } else if (this->starvingLevel < STARVING) {
    this->starvingLevel++;
  }
}
// object logic

void Predator::print() {
  std::cout << PREDATOR_N;
}
