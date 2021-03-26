// Copyright 2021 Shirokov Alexander

#include <iostream>
#include <random>
#include <ctime>
#include "../include/ocean.h"
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/stone.h"
#include "../include/coral.h"
// #include <Windows.h>

Ocean::Ocean(unsigned N, unsigned M, unsigned Predators, unsigned Preys, unsigned Stones, unsigned Corals) 
  : size{N, M} {
  cells = new Cell * [N];
  for (int i = 0; i < N; i++) {
    cells[i] = new Cell[M];
  }

  for (unsigned i = 0; i < N; i++) {
    for (unsigned j = 0; j < M; j++) {
      cells[i][j].init(Pair{ i, j }, this);
    }
  }

  addObjects(Stones, ObjType::STONE);
  addObjects(Predators, ObjType::PREDATOR);
  addObjects(Preys, ObjType::PREY);
  addObjects(Corals, ObjType::CORAL);
}

Ocean::~Ocean() {
  for (int i = 0; i < size.x; i++) {
    delete[] cells[i];
  }
  delete[] cells;
}

void Ocean::print() const {
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      if (cells[i][j].getObject() != nullptr) {
        std::cout << cells[i][j].getObject()->getSymbol();
      }
      else {
        std::cout << '.';
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl << std::endl;
}

void Ocean::addObjects(int num, ObjType type) {
  std::mt19937 gen;
  gen.seed(time(0));
  int x, y;

  for (int i = 0; i < num; i++) {
    x = gen() % this->size.x;
    y = gen() % this->size.y;
    while (this->cells[x][y].getObject() != nullptr) {
      x = gen() % this->size.x;
      y = gen() % this->size.y;
    }
    Object* object{ nullptr };
    switch (type) {
      case ObjType::STONE:
        object = new Stone(&cells[x][y]);
        break;
      case ObjType::PREDATOR:
        object = new Predator((&cells[x][y]));
        break;
      case ObjType::PREY:
        object = new Prey(&cells[x][y]);
        break;
      case ObjType::CORAL:
        object = new Coral(&cells[x][y]);
        break;
    }
    this->cells[x][y].setObject(object);
    stuff.push_back(object);
  }
}

void Ocean::addObject(Object* obj) {
  this->stuff.push_back(obj);
}

void Ocean::run() {
  this->print();
  std::cout << "Iteration: 1";
  //Sleep(3000);
  //system("cls");
  int iteration = 2;
  while (this->stuff.size() != 0) {
    for (auto& obj : this->stuff) {
      obj->live();
    }
    this->clearKilledList();
    this->print();
    std::cout << "Iteration: " << iteration;
    iteration++;
    //Sleep(3000);
    //system("cls");
  }
}

void Ocean::addToKilledList(Object* obj) {
  if (obj != nullptr) {
    killed.push_back(obj);
  }
}

void Ocean::clearKilledList() {
  for (auto& item : this->killed) {
    this->stuff.remove(item);
    item->setCell(nullptr);
  }
  killed.clear();
}

Cell* Ocean::findEmpty(Pair crd) {
  std::vector<Cell*> cells;
  for (int i = crd.x - 1; i <= crd.x + 1; i++) {
    for (int j = crd.y - 1; j <= crd.y + 1; j++) {
      Cell* tmp = &(this->cells[i % this->size.x][j % this->size.y]);
      if (tmp->getObject() == nullptr) {
        cells.push_back(tmp);
      }
    }
  }
  if (cells.empty()) {
    return nullptr;
  }
  else {
    return cells[rand() % cells.size()];
  }
}

Cell* Ocean::findPrey(Pair crd) {
  std::vector<Cell*> food;
  for (int i = crd.x - 1; i <= crd.x + 1; i++) {
    for (int j = crd.y - 1; j <= crd.y + 1; j++) {
      Cell* tmp = &(this->cells[i % this->size.x][j % this->size.y]);
      if (tmp->getObject() != nullptr &&
        tmp->getObject()->getType() == ObjType::PREY) {
        food.push_back(tmp);
      }
    }
  }
  if (food.empty()) {
    return nullptr;
  }
  else {
    return food[rand() % food.size()];
  }
}
