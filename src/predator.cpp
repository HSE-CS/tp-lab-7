//// Copyright 2021 Lukicheva Polina
#include "../include/predator.h"
#include "../include/object.h"
#include "../include/cell.h"

void Predator::live() {
  int health = 0, multCounter = 0, multiPoint = 0;
  if (health)
  eat();
  if (hunger > 0) {
    if (multCounter >= multiPoint) {
      multCounter = 0;
    }
    else {
      multCounter += 1;
    }
  }
  else {
    health -= 1;
  }
}
void Predator::setCell(Cell* cell_) {
  cell = cell_;
}

void Predator::eat() {
  Cell* c = cell;
  if (c == nullptr) {
    if (hunger > 0)
      hunger -= 1;
    move();
    return;
  }
  delete c->getObject();
  cell->setObject(this);
  cell->setObject(nullptr);
  setCell(cell);
  hunger += 1;
}
//void Predator::multi() {
//  Cell* cell_for_multi = getCell()->getOcean()->findCell(cell);
//  if (cell_for_multi == nullptr) {
//    return;
//  }
//  Predator* predator = new Predator(cell_for_multi);
//  cell_for_multi->setObject(predator);
//  getCell()->getOcean()->addObject(predator);
//}

