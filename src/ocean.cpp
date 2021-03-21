// Copyright 2020 GHA Test Team
#include "../include/ocean.h"
#include <iostream>


Ocean::Ocean() {
  size_x = size_y = stones_n = preys_n = predators_n =
    prey_live_num = predator_live_num = prey_food_n_to_reproduce =
    predator_food_n_to_reproduce = objects_num = 0;
  print_delay = 0;
  cells = nullptr;
}

Ocean::Ocean(unsigned int size_x, unsigned size_y, unsigned stones_n,
  unsigned preys_n, unsigned predators_n, unsigned prey_live_num,
  unsigned prey_food_n_to_reproduce, unsigned predator_live_num,
  unsigned predator_food_n_to_reproduce, int print_delay) {
  this->size_x = size_x;
  this->size_y = size_y;
  this->stones_n = stones_n;
  this->preys_n = preys_n;
  this->objects_num = stones_n + preys_n + predators_n;
  this->predators_n = predators_n;
  this->prey_live_num = prey_live_num;
  this->predator_live_num = predator_live_num;
  this->prey_food_n_to_reproduce = prey_food_n_to_reproduce;
  this->predator_food_n_to_reproduce = predator_food_n_to_reproduce;
  this->print_delay = print_delay;
  init_cells();
  addObjects();
}

void Ocean::init_cells() {
  cells = new Cell * [size_x];
  for (unsigned i = 0; i < size_x; i++) {
    cells[i] = new Cell[size_y];
    for (unsigned j = 0; j < size_y; j++) {
      cells[i][j].init(*(new Pair(i, j)), this);
    }
  }
}

Ocean::~Ocean() {
  for (unsigned i = 0; i < size_x; i++) {
    delete[] cells[i];
  }
  delete[] cells;
}

void Ocean::print() const {
  system("cls");
  for (unsigned i = 0; i < size_x; i++) {
    for (unsigned j = 0; j < size_y; j++) {
      if (cells[i][j].isEmpty()) {
        std::cout << EMPTY_CELL;
      } else {
        switch (cells[i][j].getObject()->getObjectType()) {
        case ObjType::STONE:
          std::cout << STONE_N;
          break;
        case ObjType::PREY:
          std::cout << PREY_N;
          break;
        case ObjType::PREDATOR:
          std::cout << PREDATOR_N;
          break;
        }
      }
    }
    std::cout << std::endl;
  }
  std::cout << "PREYS NUM: " << preys_n << "PREDATORS NUM: "
   << predators_n << std::endl;
  Sleep(print_delay);
}

void Ocean::createObjects() {
  srand(time(NULL));
  std::vector<Object*> objects;
  for (unsigned i = 0; i < stones_n; i++) {
    Object* stone = new Stone();
    objects.push_back(stone);
  }
  for (unsigned i = 0; i < preys_n; i++) {
    Object* prey = new Prey(prey_live_num,
      prey_food_n_to_reproduce);
    objects.push_back(prey);
  }
  for (unsigned i = 0; i < predators_n; i++) {
    Object* predator = new Predator(predator_live_num,
      predator_food_n_to_reproduce);
    objects.push_back(predator);
  }
  unsigned len = objects_num;
  for (unsigned i = 0; i < objects_num; i++) {
    unsigned index = std::rand() % len;
    stuff.push_back(objects.at(index));
    len--;
    objects.erase(objects.begin() + index);
  }
}

void Ocean::addObjects() {
  createObjects();
  srand(time(NULL));
  for (Object* obj : stuff) {
    int i_index = std::rand() % size_x;
    int j_index = std::rand() % size_y;
    int k = 0;
    bool exit = false;
    while (cells[i_index][j_index].getObject() != nullptr && k < 5) {
      i_index = std::rand() % size_x;
      j_index = std::rand() % size_y;
      k++;
    }
    if (cells[i_index][j_index].getObject() != nullptr) {
      for (int i = 0; i < size_x; i++) {
        if (exit) {
          break;
        }
        for (int j = 0; j < size_y; j++) {
          if (cells[i][j].getObject() == nullptr) {
            exit = true;
            i_index = i;
            j_index = j;
            break;
          }
        }
      }
    }
    obj->setCell(&cells[i_index][j_index]);
    cells[i_index][j_index].setObject(obj);
    cells[i_index][j_index].setIsEmpty(false);
  }
}

void Ocean::run() {
  print();
  while (true) {
    for (Object* obj : stuff) {
      obj->live();
    }
    killObjects();
    reproduceObjects();
    print();
    if (preys_n <= 0 || predators_n <= 0) {
      break;
    }
  }
}

unsigned Ocean::getSize_x() const {
  return size_x;
}

unsigned Ocean::getSize_y() const {
  return size_y;
}

Cell** Ocean::getCells() const {
  return cells;
}

void Ocean::addObjectToDie(Object* obj) {
  objectsToDie.push_back(obj);
}

void Ocean::addObjectToReproduce(Object* obj) {
  objectsToReproduce.push_back(obj);
}

void Ocean::killObjects() {
  for (Object* obj : objectsToDie) {
    Cell* cell = obj->getCell();
    stuff.remove(obj);
    cell->setIsEmpty(true);
  }
  objectsToDie.clear();
}

void Ocean::reproduceObjects() {
  for (Object* obj : objectsToReproduce) {
    Cell* cell = obj->getCell();
    cell->setObject(obj);
    cell->setIsEmpty(false);
    stuff.push_back(obj);
  }
  objectsToReproduce.clear();
}

void Ocean::decPreysNum() {
  preys_n--;
}

void Ocean::incPreysNum() {
  preys_n++;
}

void Ocean::decPredatorsNum() {
  predators_n--;
}

void Ocean::incPredatorsNum() {
  predators_n++;
}
