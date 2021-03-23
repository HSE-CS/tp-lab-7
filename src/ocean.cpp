// Copyright 2020 Konina Tatiana
#include <time.h>
#include <iostream>
#include <cstdlib>


#include "../include/ocean.h"
#include "../include/stone.h"
#include "../include/object.h"

Ocean::Ocean() {
  cells = new Cell * [N];
  for (auto i = 0; i < N; i++) {
    cells[i] = new Cell[M];
    for (auto j = 0; j < M; j++) {
      cells[i][j].init(Pair{ i, j }, this);
    }
  }
}


void Ocean::print() const {
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < M; j++) {
      if (cells[i][j].getObject()) {
        std::cout << cells[i][j].getObject()->getSymbol();
        } else {
        std::cout << '.';
      }
    }
    std::cout << std::endl;
  }
}

void Ocean::addObjects(unsigned int n, ObjType type) {
  for (int i = n; i > 0; i--) {
    unsigned int seed = time(nullptr);
    unsigned int x = rand_r(&seed) % M;
    unsigned int y = rand_r(&seed) % N;
    if (cells[y][x].getObject()) {
      i++;
      continue;
    } else {
      Object* obj = nullptr;
      if (type == ObjType::PREY) {
        obj = new Prey(&cells[y][x]);
      } else if (type == ObjType::STONE) {
        obj = new Stone(&cells[y][x]);
      } else if (type == ObjType::PREDATOR) {
        obj = new Predator(&cells[y][x]);
      }
      cells[y][x].setObject(obj);
      stuff.push_back(obj);
    }
  }
}

void Ocean::run() {
  while (true) {
    std::cout << "\x1b[0m";
    clock_t now = clock();
    print();
    while (clock() < now + CLOCKS_PER_SEC / 10) {
      continue;
    }
    for (std::list<Object*>::iterator i = stuff.begin();
      i != stuff.end(); ++i) {
      if ((*i)->getState()) {
        (*i)->getCell()->killMe();
        stuff.erase(i);
      } else {
         (*i)->live();
      }
    }
  }
}

Cell* Ocean::moveObj(Pair crd) {
  unsigned int seed = time(nullptr);
  int xt = (crd.x + rand_r(&seed) % 3 - 1) % N;
  int yt = (crd.y + rand_r(&seed) % 3 - 1) % M;
  return &cells[xt][yt];
}
Ocean::~Ocean() {
  for (int i = 0; i < N; i++) {
    delete[] cells[i];
  }
  delete[] cells;
  for (auto i = stuff.begin(); i != stuff.end(); ++i) {
    delete* i;
  }
}


void Ocean::addObj(Object* obj) {
  stuff.push_back(obj);
}



