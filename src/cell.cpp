// Copyright by Egor Bodrov 2021

#include "cell.h"

Cell::Cell(pair coords, Ocean* ocean)
    : loc{coords}, ocean{ocean}, obj{nullptr} {}

void Cell::init(pair coords, Ocean* ocean) {
  this->loc = coords;
  this->ocean = ocean;
}

Object* Cell::getObject() const { return this->obj; }

void Cell::setObject(Object* object) { this->obj = object; }

void Cell::killMe() {
  if (this->obj != nullptr) {
    this->ocean->addToKilledList(this->obj);
    this->obj = nullptr;
  }
}

Cell* Cell::findPlace() { return this->ocean->findEmpty(this->loc); }

Cell* Cell::findPrey() { return this->ocean->findPrey(this->loc); }

Ocean* Cell::getOcean() { return this->ocean; }
