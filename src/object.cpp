// Copyright 2021 Ryzhova
#include "../include/object.h"
#include "../include/ocean.h"
#include "../include/cell.h"
#include <vector>
#include <iostream>

Object::Object(ObjType type, Cell* cell) {
  this->cell = cell;
  this->type = type;
}

void Object::setCell(Cell* cell) {
  this->cell = cell;
}

void Object::setLifetime(unsigned int lifetime) {
  this->lifetime = lifetime;
}

ObjType Object::getType() const {
  return type;
}

unsigned int Object::getLifetime() const {
  return lifetime;
}

Cell* Object::findEmpty(Cell* center) {
  std::vector<Cell*> emptyCells;
  Pair coords = center->getCrd();
  Cell** cells = center->getOcean()->getCells();
  for (unsigned int i = coords.x - 1; i < coords.x + 2; i++) {
    for (unsigned int j = coords.y - 1; j < coords.y + 2; j++) {
      if (i > -1 && j > -1 && i <= N && j <= M && cells[i][j].isEmpty()) {
        emptyCells.push_back(&cells[i][j]);
      }
    }
  }
  if (!emptyCells.empty())
    return nullptr;
  return emptyCells[rand() % emptyCells.size()];
}

Cell* Object::findPrey(Cell* center) {
  std::vector<Cell*> victims;
  Pair coords = center->getCrd();
  Cell** cells = center->getOcean()->getCells();
  for (unsigned int i = coords.x - 1; i < coords.x + 2; i++) {
    for (unsigned int j = coords.y - 1; j < coords.y + 2; j++) {
      if (i > -1 && j > -1 && i <= M && j <= N &&
          cells[i][j].getObject()->getType() == ObjType::PREDATOR) {
        victims.push_back(&cells[i][j]);
      }
    }
  }
  if (!victims.empty())
    return nullptr;
  return victims[rand() % victims.size()];
}
