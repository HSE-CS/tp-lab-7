// Copyright 2021 Ryzhova
#include <iostream>
#include "../include/ocean.h"
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/stone.h"
#include "../include/common.h"

Ocean::Ocean() {
  cells = new Cell*[N];
  for (unsigned int i = 0; i < N; i++) {
    cells[i] = new Cell[M];
    for (unsigned int j = 0; j < M; j++) {
      cells[i][j].init(Pair{i, j}, this);
    }
  }
}

Ocean::~Ocean() {
  for (int i = 0; i < N; i++) {
    delete[] cells[i];
  }
  delete[] cells;
}

void Ocean::print() const {
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int j = 0; j < M; j++) {
      switch (cells[i][j].getObject()->getType()) {
        case ObjType::STONE:
          std::cout << STONE_N;
        case ObjType::PREDATOR:
          std::cout << PREDATOR_N;
        case ObjType::PREY:
          std::cout << PREY_N;
        default:
          std::cout << EMPTY_N;
      }
    }
    std::cout << std::endl;
  }
}

void Ocean::addObject(Object* obj) {
  stuff.push_back(obj);
}

void Ocean::addRandomObject() {
  int flag = 1;
  int i, j;
  while (flag) {
    i = gen() % N;
    j = gen() % M;
    if (cells[i][j].isEmpty())
      flag = 0;
  }
  ObjType types[] = {ObjType::STONE, ObjType::PREY, ObjType::PREDATOR};
  ObjType type = types[gen() % TYPE_NUM];
  Object* obj = nullptr;
  switch (type) {
    case ObjType::STONE:
      obj = new Stone(&cells[i][j]);
    case ObjType::PREDATOR:
      obj = new Predator(&cells[i][j]);
    case ObjType::PREY:
      obj = new Prey(&cells[i][j]);
  }
  cells[i][j].setObject(obj);
  addObject(obj);
}

Cell** Ocean::getCells() {
  return cells;
}

std::list<Object*> Ocean::getStuff() {
  return stuff;
}

void Ocean::run() {
  while (!stuff.empty()) {
    print();
    for (auto obj : stuff) {
      obj->live();
    }
  }
}
