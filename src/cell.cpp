// Copyright 2021 Dev-will-work
#include <algorithm>
#include "cell.h"
#include "ocean.h"

Cell::~Cell() {
  delete this->obj;
}

void Cell::init(Pair p, Ocean* oc) {
  this->crd = p;
  this->ocean = oc;
  this->field = &oc->cells;
}

Object* Cell::getObject() {
  return this->obj;
}

void Cell::setObject(Object* obj) {
  this->obj = obj;
}

void Cell::killMe() {
  if (this->obj) {
    this->obj->setCell(nullptr);
    this->ocean->almostDead.push_back(this->obj);
    this->obj = nullptr;
  }
}

size_t Cell::calcObjectsNear(ObjType obj) {
  size_t objectCount = 0;
  Pair coord = this->getCoord();

  if (coord.x > 0 && coord.y > 0 && this->getNeighbour(coord.y - 1,
      coord.x - 1).getObject() && this->getNeighbour(coord.y - 1,
        coord.x - 1).getObject()->getType() == obj) {
    objectCount++;
  }
  if (coord.x > 0 && this->getNeighbour(coord.y,
    coord.x - 1).getObject() && this->getNeighbour(coord.y,
      coord.x - 1).getObject()->getType() == obj) {
    objectCount++;
  }
  if (coord.x > 0 && coord.y < N - 1 && this->getNeighbour(coord.y + 1,
    coord.x - 1).getObject() && this->getNeighbour(coord.y + 1,
      coord.x - 1).getObject()->getType() == obj) {
    objectCount++;
  }
  if (coord.y > 0 && this->getNeighbour(coord.y - 1,
    coord.x).getObject() && this->getNeighbour(coord.y - 1,
      coord.x).getObject()->getType() == obj) {
    objectCount++;
  }
  if (coord.y < N - 1 && this->getNeighbour(coord.y + 1,
    coord.x).getObject() && this->getNeighbour(coord.y + 1,
      coord.x).getObject()->getType() == obj) {
    objectCount++;
  }
  if (coord.x < M - 1 && coord.y > 0 && this->getNeighbour(coord.y - 1,
    coord.x + 1).getObject() && this->getNeighbour(coord.y - 1,
      coord.x + 1).getObject()->getType() == obj) {
    objectCount++;
  }
  if (coord.x < M - 1 && this->getNeighbour(coord.y,
    coord.x + 1).getObject() && this->getNeighbour(coord.y,
      coord.x + 1).getObject()->getType() == obj) {
    objectCount++;
  }
  if (coord.x < M - 1 && coord.y < N - 1 && this->getNeighbour(coord.y + 1,
    coord.x + 1).getObject() && this->getNeighbour(coord.y + 1,
      coord.x + 1).getObject()->getType() == obj) {
    objectCount++;
  }
  return objectCount;
}

Cell* Cell::getAnyNeighbourCell(ObjType* habitant) {
  Pair coord = this->getCoord();

  // |1|4|6|
  // |2|X|7|
  // |3|5|8|

  if (coord.x > 0 && coord.y > 0 &&
    (!this->getNeighbour(coord.y - 1, coord.x - 1).getObject() ||
    habitant &&
      this->getNeighbour(coord.y - 1,
        coord.x - 1).getObject()->getType() == *habitant)) {
    return &this->getNeighbour(coord.y - 1, coord.x - 1);
  } else if (coord.x > 0 &&
    (!this->getNeighbour(coord.y, coord.x - 1).getObject() ||
    habitant &&
      this->getNeighbour(coord.y,
        coord.x - 1).getObject()->getType() == *habitant)) {
    return &this->getNeighbour(coord.y, coord.x - 1);
  } else if (coord.x > 0 && coord.y < N - 1 &&
    (!this->getNeighbour(coord.y + 1, coord.x - 1).getObject() ||
    habitant &&
      this->getNeighbour(coord.y + 1,
        coord.x - 1).getObject()->getType() == *habitant)) {
    return &this->getNeighbour(coord.y + 1, coord.x - 1);
  } else if (coord.y > 0 &&
    (!this->getNeighbour(coord.y - 1, coord.x).getObject() ||
    habitant && this->getNeighbour(coord.y - 1,
      coord.x).getObject()->getType() == *habitant)) {
    return &this->getNeighbour(coord.y - 1, coord.x);
  } else if (coord.y < N - 1 &&
    (!this->getNeighbour(coord.y + 1, coord.x).getObject() ||
    habitant && this->getNeighbour(coord.y + 1,
      coord.x).getObject()->getType() == *habitant)) {
    return &this->getNeighbour(coord.y + 1, coord.x);
  } else if (coord.x < M - 1 && coord.y > 0 &&
    (!this->getNeighbour(coord.y - 1, coord.x + 1).getObject() ||
    habitant && this->getNeighbour(coord.y - 1,
      coord.x + 1).getObject()->getType() == *habitant)) {
    return &this->getNeighbour(coord.y - 1, coord.x + 1);
  } else if (coord.x < M - 1 &&
    (!this->getNeighbour(coord.y, coord.x + 1).getObject() ||
    habitant && this->getNeighbour(coord.y,
      coord.x + 1).getObject()->getType() == *habitant)) {
    return &this->getNeighbour(coord.y, coord.x + 1);
  } else if (coord.x < M - 1 && coord.y < N - 1 &&
    (!this->getNeighbour(coord.y + 1, coord.x + 1).getObject() ||
    habitant && this->getNeighbour(coord.y + 1,
      coord.x + 1).getObject()->getType() == *habitant)) {
    return &this->getNeighbour(coord.y + 1, coord.x + 1);
  } else {
    return nullptr;
  }
}


Ocean* Cell::getOcean() {
  return this->ocean;
}

Pair Cell::getCoord() {
  return this->crd;
}

Cell& Cell::getNeighbour(coord_t row, coord_t column) {
  return (*this->field)[row][column];
}
