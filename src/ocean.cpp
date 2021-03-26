// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#include <zconf.h>
#include <random>
#include "../include/ocean.h"

static std::mt19937_64 rang;

Ocean::Ocean() {
  this->cells = new Cell *[M];
  for (auto itM = 0; itM < M; itM++) {
    cells[itM] = new Cell[N];
    for (int itN = 0; itN < N; itN++) {
      cells[itM][itN].initial(Pair({static_cast<coord_t>(itM),
                             static_cast<coord_t>(itN)}),
                       this);
    }
  }
}

Ocean::~Ocean() {
  for (int itM = 0; itM < M; itM++) {
    delete[] cells[itM];
  }
  delete[] cells;
}


[[noreturn]] void Ocean::run() {
  int count = 0;
  while (true) {
    for (auto &obj : stuff) {
      if (obj == nullptr ||
          obj->getObjType() == ObjType::EMPTY) {
        continue;
      }
      obj->live();
      if (obj->getObjType() == ObjType::PREY ||
          obj->getObjType() == ObjType::PREDATOR) {
        count++;
      }
    }
    this->deleteObj();
    this->print();
    sleep(1);
    if (count == 0) {
      exit(0);
    }
    count = 0;
  }
}
Cell **Ocean::getMatrix() {
  return this->cells;
}
void Ocean::fill(float percentPrey,
                      float percentPredator,
                      float percentStone) {
  int preyAmount = static_cast<int>(percentPrey * M * N);
  for (int i = 0; i < preyAmount; ++i) {
    while (true) {
      int x = static_cast<int>(rang() % M);
      int y = static_cast<int>(rang() % N);
      if (cells[x][y].obj == nullptr) {
        Object *newPrey = new Prey
            (ObjType::PREY, &cells[x][y]);
        cells[x][y].obj = newPrey;
        stuff.push_back(newPrey);
        break;
      }
    }
  }
  int predatorAmount = static_cast<int>(percentPredator * M * N);
  for (int i = 0; i < predatorAmount; ++i) {
    while (true) {
      int x = static_cast<int>(rang() % M);
      int y = static_cast<int>(rang() % N);
      if (cells[x][y].obj == nullptr) {
        Object *newPredator = new Predator
            (ObjType::PREDATOR, &cells[x][y]);
        cells[x][y].obj = newPredator;
        stuff.push_back(newPredator);
        break;
      }
    }
  }
  int stoneAmount = static_cast<int>(percentStone * M * N);
  for (int itM = 0; itM < stoneAmount; itM++) {
    while (true) {
      int x = static_cast<int>(rang() % M);
      int y = static_cast<int>(rang() % N);
      if (cells[x][y].obj == nullptr) {
        Object *newStone = new Stone
            (ObjType::STONE, &cells[x][y]);
        cells[x][y].obj = newStone;
        stuff.push_back(newStone);
        break;
      }
    }
  }
}



void Ocean::print() const {
  for (int itM = 0; itM < M; itM++) {
    for (int itN = 0; itN < N; itN++) {
      Object *object = cells[itM][itN].getObject();
      if (object == nullptr) {
        std::cout << EMPTY_N;
      } else {
        ObjType type = object->getObjType();
        if (type == ObjType::PREDATOR) {
          std::cout << PREDATOR_N;
        } else if (type == ObjType::PREY) {
          std::cout << PREY_N;
        } else if (type == ObjType::STONE) {
          std::cout<< STONE_N;
        } else if (type == ObjType::EMPTY) {
          std::cout << EMPTY_N;
        }
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}



void Ocean::deleteObj() {
  for (auto &obj : DeletedEntities) {
    stuff.remove(obj);
    delete obj;
  }
  DeletedEntities.clear();
}

void Ocean::addDeletedEntities(Object *obj) {
  DeletedEntities.push_back(obj);
}

void Ocean::addObjects(Object *newObj) {
  stuff.push_back(newObj);
}




