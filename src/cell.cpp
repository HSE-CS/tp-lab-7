// Copyright 2021 ArinaMonicheva

#include "cell.h"

void Cell::init(coords newCds, Ocean* ocean) {
  currentCds.x = newCds.x;
  currentCds.y = newCds.y;
  this->ocean = ocean;
  empty = true;
  inhabitant = nullptr;
}

Object* Cell::getObject() const {
  return inhabitant;
}

void Cell::setObject(Object* newInhabitant) {
  //if (!empty) {
  //    throw "Alredy occupied";
  //}
  inhabitant = newInhabitant;
  empty = false;
}

void Cell::freeMe() {
  inhabitant = nullptr;
  empty = true;
}

coords Cell::getCoords() {
  return currentCds;
}

Ocean* Cell::getOcean() const {
  return ocean;
}

bool Cell::isEmpty() {
  return empty;
}
