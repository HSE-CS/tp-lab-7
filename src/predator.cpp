// Copyright 2021 Elise
#include "../include/predator.h"


Predator::Predator(Cell* cell) : Object(cell) {
  this->time = 15;
  this->type_object = PREDATOR_N;
  this->food =  0;
}

void Predator::live() {
  if (time > 0) {
    sail();
    if (time % 6 == 0) {
      eat();
    }
    if (time % 3 == 0) {
      babies();
    }
    time--;
  } else {
    this->cell->killMe();
  }
}

void Predator::sail() {
  Cell* new_cell = cell->newCell();
  if (new_cell) {
    this->cell->setObject(nullptr);
    this->cell = new_cell;
    this->cell->setObject(this);
  }
}

void Predator::eat() {
  Cell* new_cell = this->cell->lets_go_eat();
  if (new_cell) {
    new_cell->killMe();
    cell->setObject(nullptr);
    cell = new_cell;
    cell->setObject(this);
    time += 1;
    food += 1;
  } else {
    new_cell = cell->newCell();
    if (new_cell) {
      cell->setObject(nullptr);
      cell = new_cell;
      cell->setObject(this);
    }
  }
}


void Predator::babies() {
    Cell* new_cell = cell->newCell();
    if (new_cell) {
      Predator* new_predator = new Predator(new_cell);
      new_cell->setObject(new_predator);
      new_cell->getOcean()->addObject(new_predator);
    }
  }
