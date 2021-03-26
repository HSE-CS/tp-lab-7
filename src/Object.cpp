// Copyright 2021 by me
#include "../include/Object.h"
#include "../include/cell.h"


void Object::setCell(Cell* ncell) { cell = ncell; }

void Object::print() {
  switch (type) {
    case ObjType::STONE:
      std::cout << STONE_N;
      break;
    case ObjType::CORAL:
      std::cout << CORAL_N;
      break;
    case ObjType::PREY:
      std::cout << PREY_N;
      break;
    case ObjType::PREDATOR:
      std::cout << PREDATOR_N;
      break;
    default:
      break;
  }
}

Pair Object::getCoord() { return cell->getCoord(); }

Cell* Object::getCell() { return cell; }

ObjType Object::getType() {
  if (this == nullptr) return ObjType::EMPTY;
  return type;
}
