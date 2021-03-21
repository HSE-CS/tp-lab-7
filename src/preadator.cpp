// Copyright 2020 GHA Test Team
#include "../include/predator.h"
#include "../include/ocean.h"


Predator::Predator() {
  this->cell = nullptr;
  live_count = food_n_to_reproduce = max_live_count =
    init_food_n_to_reproduce = 0;
  obj_type = ObjType::PREDATOR;
}

Predator::Predator(unsigned live_count,
  unsigned food_n_to_reproduce) {
  this->cell = nullptr;
  this->live_count = live_count;
  this->food_n_to_reproduce = food_n_to_reproduce;
  this->max_live_count = live_count;
  this->init_food_n_to_reproduce = food_n_to_reproduce;
  obj_type = ObjType::PREDATOR;
}

void Predator::live() {
  Ocean* ocean = cell->getOcean();
  Pair cur_pos = *(new Pair(cell->getCrd().x, cell->getCrd().y));
  Pair new_pos = findPosition(ocean);
  move(cur_pos, new_pos, ocean);
  live_count -= 1;
  if (live_count <= 0) {
    ocean->addObjectToDie(reinterpret_cast<Object*>(this));
    cell->setObject(nullptr);
    ocean->decPredatorsNum();
    return;
  }
  if (food_n_to_reproduce <= 0) {
    food_n_to_reproduce = init_food_n_to_reproduce;
    Pair new_pos = findPosition(ocean);
    if (reproduce(new_pos, ocean)) {
      ocean->incPredatorsNum();
    }
  }
}

bool Predator::reproduce(Pair new_pos, Ocean* ocean) {
  Cell** cells = ocean->getCells();
  Cell* cell = &cells[new_pos.x][new_pos.y];
  if (cell->isEmpty() && cell->getObject() == nullptr) {
    Object* other = cell->getObject();
    Object* child = new Predator(max_live_count, init_food_n_to_reproduce);
    child->setCell(cell);
    ocean->addObjectToReproduce(child);
    cell->setIsEmpty(false);
    return true;
  }
  return false;
}

void Predator::move(Pair cur_pos, Pair new_pos, Ocean* ocean) {
  Cell** cells = ocean->getCells();
  Cell* cell = &cells[new_pos.x][new_pos.y];
  Object* other = cells[new_pos.x][new_pos.y].getObject();
  bool isPrey = !cell->isEmpty() && other != nullptr &&
    other->getObjectType() == ObjType::PREY;
  if (isPrey) {
    food_n_to_reproduce -= 1;
    live_count = max_live_count;
    ocean->addObjectToDie(other);
    ocean->decPreysNum();
  }
  if (cell->isEmpty() && other == nullptr || isPrey) {
    this->cell = cell;
    this->cell->setObject(reinterpret_cast<Object*>(this));
    this->cell->setIsEmpty(false);
    cells[cur_pos.x][cur_pos.y].setIsEmpty(true);
    cells[cur_pos.x][cur_pos.y].setObject(nullptr);
  }
}
