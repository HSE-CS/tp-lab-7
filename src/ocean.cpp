// Copyright by Egor Bodrov 2021

#include "../include/ocean.h"
#include "../include/stone.h"
#include "../include/predator.h"
#include "../include/prey.h"
#include <iostream>
#include <random>
#include <vector>
#include <ctime>

Ocean::Ocean(unsigned N, unsigned M, unsigned PredNum, unsigned PreyNum,
             unsigned StoneNum)
    : size{N, M} {
  surface = new Cell *[N];
  for (int i = 0; i < N; i++) {
    surface[i] = new Cell[M];
  }

  for (unsigned i = 0; i < N; i++) {
    for (unsigned j = 0; j < M; j++) {
      surface[i][j].init(pair{i, j}, this);
    }
  }

  addObjects(StoneNum, ObjectType::STONE);
  addObjects(PredNum, ObjectType::PREDATOR);
  addObjects(PreyNum, ObjectType::PREY);
}

Ocean::~Ocean() {
  for (int i = 0; i < size.x; i++) {
    delete[] surface[i];
  }
  delete[] surface;
}

void Ocean::print() const {
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      if (surface[i][j].getObject() != nullptr) {
        std::cout << surface[i][j].getObject()->getSymbol();
      } else {
        std::cout << EMPTY_N;
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl << std::endl;
}

void Ocean::addObjects(int num, ObjectType type) {
  std::mt19937 gen;
  gen.seed(time(0));
  int x, y;

  for (int i = 0; i < num; i++) {
    x = gen() % this->size.x;
    y = gen() % this->size.y;
    
    while (this->surface[x][y].getObject() != nullptr) {
      x = gen() % this->size.x;
      y = gen() % this->size.y;
    }
    
    Object *new_object{nullptr};
    switch (type) {
      case ObjectType::STONE:
        new_object = new Stone(&surface[x][y]);
        break;
      case ObjectType::PREDATOR:
        new_object = new Predator((&surface[x][y]));
        break;
      case ObjectType::PREY:
        new_object = new Prey(&surface[x][y]);
        break;
    }

    this->surface[x][y].setObject(new_object);
    stuff.push_back(new_object);
  }
}

void Ocean::run() {
  this->print();
  while (this->stuff.empty() == false) {
    for (auto &obj : this->stuff) {
      obj->live();
    }

    this->clearKilledList();
    this->print();
  }
}

void Ocean::addObject(Object *obj) { this->stuff.push_back(obj); }

void Ocean::addToKilledList(Object *obj) {
  if (obj != nullptr) {
    killed.push_back(obj);
  }
}

void Ocean::clearKilledList() {
  for (auto &el : this->killed) {
    this->stuff.remove(el);
    el->setCell(nullptr);
  }
  killed.clear();
}

Cell* Ocean::findPrey(pair coord) {
  std::vector<Cell *> preys;
  for (int i = coord.x - 1; i <= coord.x + 1; i++) {
    for (int j = coord.y - 1; j <= coord.y + 1; j++) {
      Cell *tmp = &(this->surface[i % this->size.x][j % this->size.y]);
      if (tmp->getObject() != nullptr &&
          tmp->getObject()->getType() == ObjectType::PREY) {
        preys.push_back(tmp);
      }
    }
  }

  if (preys.empty()) {
    return nullptr;
  } else {
    return preys[rand() % preys.size()];
  }
}

Cell* Ocean::findEmpty(pair coord) {
  std::vector<Cell *> cells;
  for (int i = coord.x - 1; i <= coord.x + 1; i++) {
    for (int j = coord.y - 1; j <= coord.y + 1; j++) {
      Cell *tmp = &(this->surface[i % this->size.x][j % this->size.y]);
      if (tmp->getObject() == nullptr) {
        cells.push_back(tmp);
      }
    }
  }

  if (cells.empty()) {
    return nullptr;
  } else {
    return cells[rand() % cells.size()];
  }
}
