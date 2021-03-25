// Copyright NikDemoShow 2021
#include"cell.h"
#include "ocean.h"
Cell* Cell::getFreeNeighbour(const bool hungry) {
  int dx{ std::rand() % 3 - 1 },
    dy{ (std::rand() % 3 - 1) * (dx == 0) };
  while (!(dx + dy)) {
    dx = std::rand() % 3 - 1;
    dy = (std::rand() % 3 - 1) * (dx == 0);
  }
  Cell* newCell{ nullptr };
  Cell* newCellForHungry{ nullptr };
  if (this->crd.x + dx < M && this->crd.y + dy < N) {
    newCell = this->ocean->getCell(this->crd.x + dx, this->crd.y + dy);
    if (!newCell->getObject()) {
      if (hungry) {
        newCellForHungry = newCell;
      }
      else {
        return newCell;
      }
    }
    else {
      if (hungry && newCell->getObjectType() == ObjType::PREY) {
        return newCell;
      }
    }
  }
  dy *= -1;
  if (this->crd.x + dx < M && this->crd.y + dy < N) {
    newCell = this->ocean->getCell(this->crd.x + dx, this->crd.y + dy);
    if (!newCell->getObject()) {
      if (hungry && !newCell) {
        newCellForHungry = newCell;
      }
      else {
        return newCell;
      }
    }
    else {
      if (hungry && newCell->getObjectType() == ObjType::PREY) {
        return newCell;
      }
    }
  }
  std::swap(dx, dy);
  if (this->crd.x + dx < M && this->crd.y + dy < N) {
    newCell = this->ocean->getCell(this->crd.x + dx, this->crd.y + dy);
    if (!newCell->getObject()) {
      if (hungry && !newCell) {
        newCellForHungry = newCell;
      }
      else {
        return newCell;
      }
    }
    else {
      if (hungry && newCell->getObjectType() == ObjType::PREY) {
        return newCell;
      }
    }
  }
  dx *= -1;
  if (this->crd.x + dx < M && this->crd.y + dy < N) {
    newCell = this->ocean->getCell(this->crd.x + dx, this->crd.y + dy);
    if (!newCell->getObject()) {
      if (!hungry || !newCellForHungry) {
        return newCell;
      }
    }
    else {
      if (hungry && newCell->getObjectType() == ObjType::PREY) {
        return newCell;
      }
    }
  }
  return newCellForHungry;
}

Object* Cell::getObject() const{ return this->obj; }
ObjType Cell::getObjectType() const {return this->obj->type;}
void Cell::setObject(Object* newObj) { this->obj = newObj; }
void Cell::addObject(const ObjType type, Cell* newCell) { this->ocean->addObject(type, newCell); }
