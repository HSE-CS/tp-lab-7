// Copyright TimurZaytsev 2021
#include "../include/cell.h"

#include "../include/ocean.h"
Cell* Cell::getNeighbour(const bool hunger) {
  int x{std::rand() % 3 - 1}, y{(std::rand() % 3 - 1) * (x == 0)};
  while (!(x + y)) {
    x = std::rand() % 3 - 1;
    y = (std::rand() % 3 - 1) * (x == 0);
  }
  Cell* newCell{nullptr};
  Cell* newCellForPredator{nullptr};
  if (this->crd.x + x < M && this->crd.y + y < N) {
    newCell = this->ocean->getCell(this->crd.x + x, this->crd.y + y);
    if (!newCell->getObj()) {
      if (hunger) {
        newCellForPredator = newCell;
      } else {
        return newCell;
      }
    } else {
      if (hunger && newCell->getObjType() == ObjType::PREY) {
        return newCell;
      }
    }
  }
  y *= -1;
  if (this->crd.x + x < M && this->crd.y + y < N) {
    newCell = this->ocean->getCell(this->crd.x + x, this->crd.y + y);
    if (!newCell->getObj()) {
      if (hunger && !newCell) {
        newCellForPredator = newCell;
      } else {
        return newCell;
      }
    } else {
      if (hunger && newCell->getObjType() == ObjType::PREY) {
        return newCell;
      }
    }
  }
  std::swap(x, y);
  if (this->crd.x + x < M && this->crd.y + y < N) {
    newCell = this->ocean->getCell(this->crd.x + x, this->crd.y + y);
    if (!newCell->getObj()) {
      if (hunger && !newCell) {
        newCellForPredator = newCell;
      } else {
        return newCell;
      }
    } else {
      if (hunger && newCell->getObjType() == ObjType::PREY) {
        return newCell;
      }
    }
  }
  x *= -1;
  if (this->crd.x + x < M && this->crd.y + y < N) {
    newCell = this->ocean->getCell(this->crd.x + x, this->crd.y + y);
    if (!newCell->getObj()) {
      if (!hunger || !newCellForPredator) {
        return newCell;
      }
    } else {
      if (hunger && newCell->getObjType() == ObjType::PREY) {
        return newCell;
      }
    }
  }
  return newCellForPredator;
}

Object* Cell::getObj() const { return this->obj; }
ObjType Cell::getObjType() const { return this->obj->type; }
void Cell::setObj(Object* newObj) { this->obj = newObj; }
void Cell::addObj(const ObjType type, Cell* newCell) {
  this->ocean->addObj(type, newCell);
}
