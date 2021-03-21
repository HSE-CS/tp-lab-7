//// Copyright 2021 Ozhiganova Polina
#include <random>
#include "../include/cell.h"
#include "../include/ocean.h"

std::random_device rd;
std::mt19937 rng(rd());

void Cell::init(Pair p, Ocean *oc) {
  this->crd = p;
  this->ocean = oc;
}

Ocean *Cell::getOcean() const {
  return const_cast<Ocean *>(ocean);
}

Object *Cell::getObject() const {
  return this->obj;
}

void Cell::setObject(Object *object) {
  this->obj = object;
}

Cell *Cell::findPlace() {
  std::vector<Cell *> emptyCells;
  Cell **matrix = ocean->getMatrix();
  // directions
  Cell *up = &(matrix[crd.x - 1][crd.y]);
  Cell *down = &(matrix[crd.x + 1][crd.y]);
  Cell *right = &(matrix[crd.x][crd.y + 1]);
  Cell *left = &(matrix[crd.x][crd.y - 1]);
  if ((crd.x != 0) && (up->obj == nullptr)) {  //  UP
    emptyCells.push_back(up);
  } else if ((crd.x != M - 1) &&
      (down->obj == nullptr)) {  //  DOWN
    emptyCells.push_back(down);
  } else if ((crd.y != N - 1) &&
      (right->obj == nullptr)) {  // RIGHT
    emptyCells.push_back(right);
  } else if ((crd.y != 0) &&
      (left->obj == nullptr)) {  // LEFT
    emptyCells.push_back(left);
  }
  if (emptyCells.empty()) {
    return nullptr;
  } else {
    std::uniform_int_distribution<int>
        uni(0, emptyCells.size() - 1);
    int random_integer = uni(rng);
    return emptyCells[random_integer];
  }
}

bool Cell::checkPrey(Cell *cellToCheck) const {
  if (cellToCheck->obj == nullptr) {
    return false;
  } else if (cellToCheck->obj->getObjType() == ObjType::PREY) {
    return true;
  }
  return false;
}

Cell *Cell::goHunt() const {
  std::vector<Cell *> emptyCells;
  Cell **matrix = ocean->getMatrix();
  // directions
  Cell *up = &(matrix[crd.x - 1][crd.y]);
  Cell *down = &(matrix[crd.x + 1][crd.y]);
  Cell *right = &(matrix[crd.x][crd.y + 1]);
  Cell *left = &(matrix[crd.x][crd.y - 1]);
  if (crd.x != 0) {
    if (checkPrey(up)) {  //  UP
      emptyCells.push_back(up);
    }
  }
  if (crd.x != M - 1) {
    if (checkPrey(down)) {  //  DOWN
      emptyCells.push_back(down);
    }
  }
  if (crd.y != N - 1) {
    if (checkPrey(right)) {  // RIGHT
      emptyCells.push_back(right);
    }
  }
  if (crd.y != 0) {
    if (checkPrey(left)) {  // LEFT
      emptyCells.push_back(left);
    }
  }
  if (emptyCells.empty()) {
    return nullptr;
  } else {
    std::uniform_int_distribution<int>
        uni(0, emptyCells.size() - 1);
    int random_integer = uni(rng);
    return emptyCells[random_integer];
  }
}

void Cell::killMe() {
  this->ocean->addDeleteCreatures(obj);
  obj->setObjType(ObjType::EMPTY);
}
