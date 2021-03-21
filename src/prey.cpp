// Copyright 2020 GHA Test Team
#include "../include/prey.h"
#include "../include/ocean.h"


enum class Directions{
  TOP_LEFT, TOP, TOP_RIGHT, LEFT, RIGHT, BOTTOM_LEFT,
  BOTTOM, BOTTOM_RIGHT
};


Prey::Prey() {
  this->cell = nullptr;
  live_count = food_n_to_reproduce = init_food_n_to_reproduce =
    max_live_count = 0;
  obj_type = ObjType::PREY;
}

Prey::Prey(unsigned live_count,
  unsigned food_n_to_reproduce) {
  this->cell = nullptr;
  this->live_count = live_count;
  this->max_live_count = live_count;
  this->food_n_to_reproduce = food_n_to_reproduce;
  this->init_food_n_to_reproduce = food_n_to_reproduce;
  obj_type = ObjType::PREY;
}

void Prey::live() {
  Ocean* ocean = cell->getOcean();
  Pair cur_pos = *(new Pair(cell->getCrd().x, cell->getCrd().y));
  Pair new_pos = findPosition(ocean);
  move(cur_pos, new_pos, ocean);
  live_count -= 1;
  food_n_to_reproduce -= 1;
  if (live_count <= 0) {
    ocean->addObjectToDie(reinterpret_cast<Object*>(this));
    cell->setObject(nullptr);
    ocean->decPreysNum();
    return;
  }
  if (food_n_to_reproduce <= 0) {
    food_n_to_reproduce = init_food_n_to_reproduce;
    Pair new_pos = findPosition(ocean);
    if (reproduce(new_pos, ocean)) {
      ocean->incPreysNum();
    }
  }
}

bool Prey::reproduce(Pair new_pos, Ocean* ocean) {
  Cell** cells = ocean->getCells();
  Cell* new_cell = &cells[new_pos.x][new_pos.y];
  if (new_cell->isEmpty() && new_cell->getObject() == nullptr) {
    Object* child = new Prey(max_live_count, init_food_n_to_reproduce);
    child->setCell(new_cell);
    ocean->addObjectToReproduce(child);
    new_cell->setIsEmpty(false);
    return true;
  }
  return false;
}

Pair Prey::findPosition(Ocean* ocean) {
  Cell** cells = ocean->getCells();
  int direction = std::rand() % 8;
  unsigned i_prey = cell->getCrd().x;
  unsigned j_prey = cell->getCrd().y;
  unsigned size_x = ocean->getSize_x();
  unsigned size_y = ocean->getSize_y();
  // Calculate new coords;
  switch (direction) {
  case static_cast<int>(Directions::TOP_LEFT):
    i_prey -= 1;
    j_prey -= 1;
    break;
  case static_cast<int>(Directions::TOP):
    i_prey -= 1;
    break;
  case static_cast<int>(Directions::TOP_RIGHT):
    i_prey -= 1;
    j_prey += 1;
    break;
  case static_cast<int>(Directions::RIGHT):
    j_prey -= 1;
    break;
  case static_cast<int>(Directions::LEFT):
    j_prey += 1;
    break;
  case static_cast<int>(Directions::BOTTOM_LEFT):
    i_prey += 1;
    j_prey -= 1;
    break;
  case static_cast<int>(Directions::BOTTOM):
    i_prey += 1;
    break;
  case static_cast<int>(Directions::BOTTOM_RIGHT):
    i_prey += 1;
    j_prey += 1;
    break;
  }
  if (i_prey < 0) {
    i_prey = size_x - 1;
  }
  if (j_prey < 0) {
    j_prey = size_y - 1;
  }
  if (i_prey > size_x - 1) {
    i_prey = 0;
  }
  if (j_prey > size_y - 1) {
    j_prey = 0;
  }
  return *(new Pair(i_prey, j_prey));
}

void Prey::move(Pair cur_pos, Pair new_pos, Ocean* ocean) {
  Cell** cells = ocean->getCells();
  Cell* new_cell = &cells[new_pos.x][new_pos.y];
  if (new_cell->isEmpty() && new_cell->getObject() == nullptr) {
    this->cell = new_cell;
    this->cell->setObject(reinterpret_cast<Object*>(this));
    this->cell->setIsEmpty(false);
    cells[cur_pos.x][cur_pos.y].setIsEmpty(true);
    cells[cur_pos.x][cur_pos.y].setObject(nullptr);
  }
}
