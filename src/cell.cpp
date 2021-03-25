// Copyright 2021 Egor Trukhin
#include "cell.h"

#include "ocean.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"

Cell::Cell(coord_t position, Ocean* ocean, Object* object) {
  this->object = object;
  this->ocean = ocean;
  this->position.x = position.x;
  this->position.y = position.y;
}

void Cell::setObject(Object* object) { this->object = object; }

coord_t Cell::getPostion() const { return this->position; }

Object* Cell::getObject() const { return this->object; }

Cell* Cell::findNeighbourCell(object_t type) {
  std::vector<Cell*> neighbours, cells;
  this->ocean->getNeighbours(this->position, neighbours);
  for (auto cell : neighbours) {
    if (type == NONE && cell->object == nullptr) {
      cells.push_back(cell);
    } else if (cell->object == nullptr) {
      continue;
    } else if (cell->object->getType() == type) {
      cells.push_back(cell);
    }
  }

  if (cells.size() == 0) return nullptr;

  std::random_device rd;
  std::mt19937 gen(rd());
  return cells[gen() % cells.size()];
}

void Cell::declareBirth(Object* object) {
  this->ocean->addToBirthPool(object);
  this->object = object;
  this->object->setCell(this);
}

void Cell::declareDeath() {
  this->ocean->addToDeathPool(this->object);
  this->object->setCell(nullptr);
  this->object = nullptr;
}
