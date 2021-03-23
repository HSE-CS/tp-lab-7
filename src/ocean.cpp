// Copyright 2021 Dev-will-work
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include "../include/ocean.h"
#include "../include/stone.h"
#include "../include/predator.h"
#include "../include/prey.h"
#include "../include/common.h"

void timer(int seconds) {
  // multple calls of time() to improve painting frequency
  time_t start = time(0);
  time_t end = start + seconds;
  while (start < end) {
    start = time(0);
  }
}

Ocean::Ocean() {
  this->cells = new Cell*[N];
  for (size_t i = 0; i < N; i++) {
    this->cells[i] = new Cell[M];
    for (size_t j = 0; j < M; j++) {
      this->cells[i][j].init({j, i}, this);
    }
  }
}

Ocean::~Ocean() {
  for (size_t i = 0; i < N; i++) {
    delete[] this->cells[i];
  }
  delete[] this->cells;
}

void Ocean::print() const {
  for (size_t i = 0; i < N; i++) {
    // std::cout << i << ' ';  // showing line numbers for debug improving
    for (size_t j = 0; j < M; j++) {
      if (this->cells[i][j].obj) {
        this->cells[i][j].obj->print();
      } else {
        std::cout << '.';
      }
    }
    std::cout << "\n";
  }
}

void Ocean::addObjects(Object* objects, size_t size) {
  std::random_device rd;
  std::mt19937 mersenne(rd());

  if (objects && size > 0 && size == N * M) {
    for (size_t i = 0; i < N; i++) {
      for (size_t j = 0; j < M; j++) {
        this->cells[i][j].obj = &(*objects);
        this->cells[i][j].obj->setCell(&this->cells[i][j]);
        this->stuff.push_back(&(*objects));
        objects++;
      }
    }
  } else {
    for (size_t i = 0; i < N; i++) {
      for (size_t j = 0; j < M; j++) {
        switch (mersenne() % 4) {
          case 0:
            this->cells[i][j].obj = new Stone;
            break;
          case 1:
            this->cells[i][j].obj = new Predator;
            break;
          case 2:
            this->cells[i][j].obj = new Prey;
            break;
          default:
            break;
        }
        if (this->cells[i][j].obj) {
          this->cells[i][j].obj->setCell(&this->cells[i][j]);
          this->stuff.push_back(this->cells[i][j].obj);
        }
      }
    }
  }
}

void Ocean::run() {
  int status = 0;
  while (true) {
    timer(1);
    status = system("cls");
    this->print();
    for (auto it : this->stuff) {
      it->live();
    }
    for (size_t i = 0; i < this->almostDead.size(); i++) {  // cleaning stuff
      for (auto it = this->stuff.begin(); it != this->stuff.end();) {
        if (!(*it)->getCell()) {
          it = this->stuff.erase(std::remove(this->stuff.begin(),
                  this->stuff.end(), *it), this->stuff.end());
        } else {
        it++;
        }
      }
    }
    for (auto it : almostDead) {
      delete it;
    }
    this->almostDead.clear();
  }
}

Cell** Ocean::getCells() {
  return this->cells;
}

std::list<Object*>& Ocean::getStuff() {
  return this->stuff;
}
