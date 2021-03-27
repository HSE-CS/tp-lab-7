// Copyright [2020] <Olesya Nikolaeva>

#include <stdlib.h>
#include <time.h>
#include "ocean.h"
#include "predator.h"
#include "stone.h"

Ocean::Ocean() {
    cells = new Cell * [N];
    for (auto i = 0; i < N; i++) {
        cells[i] = new Cell[M];
        for (auto j = 0; j < M; j++) {
            cells[i][j].init(Pair{ i, j }, this);
        }
    }
}

Ocean::~Ocean() {
    for (int i = 0; i < N; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Ocean::createOcean(int preys, int predators, int stones) {
    int total = preys + predators + stones;
    for (int i = total; i > 0; i--) {
        unsigned int seed = time(nullptr);
        int x = rand_r(&seed) % N;
        int y = rand_r(&seed) % M;
        printf("%d %d", x, y);
        while (cells[y][x].getObject()) {
            x = rand_r(&seed) % N;
            y = rand_r(&seed) % M;
        }
        Object* obj = nullptr;
        if (preys > 0) {
            obj = new Prey(&cells[y][x], ObjType::PREY);
            preys--;
        } else if (predators > 0) {
            obj = new Predator(&cells[y][x]);
            predators--;
        } else if (stones > 0) {
            obj = new Stone(&cells[y][x]);
            stones--;
        }
        cells[y][x].setObject(obj);
        stuff.push_back(obj);
    }
}

void Ocean::print() const {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (cells[i][j].getObject() == nullptr) {
                std::cout << EMPTY_N;
            } else if (cells[i][j].getObject()->getObjType() == ObjType::STONE) {
                std::cout << STONE_N;
            } else if (cells[i][j].getObject()->getObjType() == ObjType::PREY) {
                std::cout << PREY_N;
            } else if (cells[i][j].getObject()->getObjType() == ObjType::PREDATOR) {
                std::cout << PREDATOR_N;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Ocean::addObjects(Object* new_object) {
    stuff.push_back(new_object);
}

void Ocean::run() {
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
      this->print();
      if (count == 0) {
        exit(0);
      }
      count = 0;
    }
}

void Ocean::deleteObject(Object* obj) {
    stuff.remove(obj);
}

bool Ocean::returnCellStatus(Pair arg) {
    return cells[arg.x][arg.y].isfree;
}

ObjType Ocean::returnObjectAtSpecificPos(Pair arg) {
    return cells[arg.x][arg.y].obj->getObjType();
}

Cell* Ocean::returnCell(Pair arg) {
    return &cells[arg.x][arg.y];
}
