// Copyright 2021 Dumarevskaya
#include "Ocean.h"
#include <iostream>
#include <stdlib.h>
//#include <unistd.h>

void Ocean::print() const {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (cells[i][j].getObject()->getObjType() == ObjType::STONE)
        std::cout << STONE_N;
      if (cells[i][j].getObject()->getObjType() == ObjType::PREY)
        std::cout << PREY_N;
      if (cells[i][j].getObject()->getObjType() == ObjType::PREDATOR)
        std::cout << PREDATOR_N;
      if (cells[i][j].getObject()->getObjType() == ObjType::EMPTY)
        std::cout << EMPTY_N;
    }
  }
}

void Ocean::addObject(Object* new_object) {
  stuff.push_back(new_object);
}

void Ocean::run() {
  int countOFpredator = 0;
  int countOFprey = 0;
  initOcean();

  while (true) {
    print();
    for (Object* obj : stuff) {
      if (obj->getObjType() == ObjType::EMPTY)
        continue;
      obj->live();
      if (obj->getObjType() == ObjType::PREY)
        countOFprey++;
      if (obj->getObjType() == ObjType::PREDATOR)
        countOFpredator++;
      print();
      deleteObjectFun();
      if (countOFpredator <= 0 || countOFprey <= 0) {
        break;
      }
    }
  }
}

void Ocean::addToDeleteObject(Object* new_object) {
  deleteObject.push_back(new_object);
}

void Ocean::deleteObjectFun() {
  for (auto &obj : deleteObject) {
    stuff.remove(obj);
    delete obj;
  }
  deleteObject.clear();
}

Cell* Ocean::getCell(int x, int y) {
  return &cells[x][y];
}

void Ocean::initOcean() {
  int seed = time(NULL);
  int* seed_p = &seed;
  int countOFstone = rand_r(seed_p) % (N * M);
  int countOFprey = countOFstone + rand_r(seed_p) % (N * M);
  int countOFpredator = countOFprey + countOFstone + rand_r(seed_p) % (N * M);
  for (int i = 0; i < countOFstone; i++) {
    while (true) {
      int x = rand_r(seed_p) % M;
      int y = rand_r(seed_p) % N;
      if (cells[x][y].getObject() == nullptr) {
        Stone* new_stone = new Stone(&cells[x][y]);
        cells[x][y].setObject(new_stone);
        stuff.push_back(new_stone);
        break;
      }
    }
  }
  for (int i = 0; i < countOFprey; i++) {
    while (true) {
      int x = rand_r(seed_p) % M;
      int y = rand_r(seed_p) % N;
      if (cells[x][y].getObject() == nullptr) {
        Prey* new_prey = new Prey(&cells[x][y]);
        cells[x][y].setObject(new_prey);
        stuff.push_back(new_prey);
        break;
      }
    }
  }for (int i = 0; i < countOFstone; i++) {
    while (true) {
      int x = rand_r(seed_p) % M;
      int y = rand_r(seed_p) % N;
      if (cells[x][y].getObject() == nullptr) {
        Predator* new_predator = new Predator(&cells[x][y]);
        cells[x][y].setObject(new_predator);
        stuff.push_back(new_predator);
        break;
      }
    }
  }

}
