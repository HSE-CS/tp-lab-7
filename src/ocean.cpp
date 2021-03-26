// Copyright 2021 mkhorosh

#include "ocean.h"
#include "common.h"
#include <vector>
#include <time.h>
#include <iostream>
#include <chrono>
#include <thread>

Ocean::Ocean(int x_size, int y_size) {
  std::vector<std::vector<Cell>> matrix(x_size, std::vector<Cell>(y_size));
  this->cells = matrix;
  for (int i = 0; i < x_size; i++) {
    for (int j = 0; j < y_size; j++) {
      Pair p{i, j};
      cells[i][j].init(p, this);
    }
  }

}
void Ocean::print() const {
  for (int i = 0; i < cells[0].size(); i++) {
    for (int j = 0; j < cells.size(); j++) {
      cells[j][i].obj->printObj();
    }
    std::cout << std::endl;
  }
}
void Ocean::addObjects(int stones, int preys, int predators) {
  int n = preys + predators + stones;
  time(nullptr);
  for (int i = n; i > 0; i--) {
    int x = rand() % M;
    int y = rand() % N;
    if (cells[x][y].getObject()) {
      i++;
      continue;
    } else {
      Object *obj = nullptr;
      if (preys > 0) {
        obj = new Prey(ObjType::PREY, &cells[x][y]);
        preys--;
      } else if (predators > 0) {
        obj = new Predator(ObjType::PREDATOR, &cells[x][y]);
        predators--;
      } else if (stones > 0) {
        obj = new Stone(ObjType::STONE, &cells[x][y]);
      }
      cells[x][y].setObject(obj);
      push(obj);
    }
  }
}

void Ocean::run() {
  int f = 0;
  while (f < 50) {
    f++;
    system("cls");
    print();
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
    for (std::list<Object *>::iterator i = stuff.begin(); i != stuff.end(); ++i) {
      if (!((*i)->isAlive())) {
        (*i)->getCell()->killMe();
      } else {
        (*i)->live();
      }
    }
  }
}

void Ocean::push(Object *o) {
  stuff.push_back(o);
}
Ocean::~Ocean() {

}
Cell *Ocean::findCell(Pair crd) {
  time(nullptr);
  int new_x = (crd.x + rand() % 2) % M;
  int new_y = (crd.y + rand() % 2) % N;
  return &(this->cells[new_x][new_y]);
}

