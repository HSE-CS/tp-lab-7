// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#include <random>
#include "../include/cell.h"
#include "../include/ocean.h"

std::random_device rd;
std::mt19937 rang(rd());

void Cell::initial(Pair p, Ocean *oc) {
  this->cord = p;
  this->ocean = oc;
}



Cell *Cell::findMove() {
  std::vector<Cell *> emptyCells;
  Cell **matrix = ocean->getMatrix();
  Cell *right = &(matrix[cord.x][cord.y + 1]);
  Cell *left = &(matrix[cord.x][cord.y - 1]);
  Cell *up = &(matrix[cord.x - 1][cord.y]);
  Cell *down = &(matrix[cord.x + 1][cord.y]);


  if ((cord.x != 0) && (up->obj == nullptr)) {
    emptyCells.push_back(up);
  } else if ((cord.x != M - 1) &&
      (down->obj == nullptr)) {
    emptyCells.push_back(down);
  } else if ((cord.y != N - 1) &&
      (right->obj == nullptr)) {
    emptyCells.push_back(right);
  } else if ((cord.y != 0) &&
      (left->obj == nullptr)) {
    emptyCells.push_back(left);
  }
  if (emptyCells.empty()) {
    return nullptr;
  } else {
    std::uniform_int_distribution<int>
        uni(0, emptyCells.size() - 1);
    int random_integer = uni(rang);
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

Cell *Cell::huntStart() const {
  std::vector<Cell *> emptyCells;
  Cell **matrix = ocean->getMatrix();
  Cell *right = &(matrix[cord.x][cord.y + 1]);
  Cell *left = &(matrix[cord.x][cord.y - 1]);
  Cell *up = &(matrix[cord.x - 1][cord.y]);
  Cell *down = &(matrix[cord.x + 1][cord.y]);
  if (cord.x != 0) {
    if (checkPrey(up)) {
      emptyCells.push_back(up);
    }
  }
  if (cord.x != M - 1) {
    if (checkPrey(down)) {
      emptyCells.push_back(down);
    }
  }
  if (cord.y != N - 1) {
    if (checkPrey(right)) {
      emptyCells.push_back(right);
    }
  }
  if (cord.y != 0) {
    if (checkPrey(left)) {
      emptyCells.push_back(left);
    }
  }
  if (emptyCells.empty()) {
    return nullptr;
  } else {
    std::uniform_int_distribution<int>
        uni(0, emptyCells.size() - 1);
    int random_integer = uni(rang);
    return emptyCells[random_integer];
  }
}

void Cell::killMe() {
  this->ocean->addDeletedEntities(obj);
  obj->setObjType(ObjType::EMPTY);
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