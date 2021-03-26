// Copyright 2021 Schenikova
#include <exception>

#include "../include/prey.h"

void Prey::step() {
  int x = this->cell->coords.x;
  int y = this->cell->coords.y;
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      try {
        if (i >= 0 && i < N && j >= 0 && j < M) {
          if (this->cell->ocean->cells[i][j].getObject() == nullptr) {
            this->cell->setObject(nullptr);
            this->cell->ocean->cells[i][j].setObject(this);
            return;
          }
        }
      }
      catch(const std::exception& e) {
      }
    }
  }
}

void Prey::create() {
  int x = this->cell->coords.x;
  int y = this->cell->coords.y;
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      try {
        if (i >= 0 && i < N && j >= 0 && j < M) {
          if (this->cell->ocean->cells[i][j].getObject() == nullptr) {
            Prey* tmp = new Prey;
            this->cell->ocean->cells[i][j].setObject(tmp);
            // this->cell->ocean->addObjects(std::vector<Object *>{tmp});
            return;
          }
        }
      }
      catch(const std::exception& e) {
      }
    }
  }
}

void Prey::live() {
  if (!this->numberOfLive) {
    this->cell->killMe();
    return;
  }
  this->numberOfLive--;
  step();
  if (!((this->len - this->numberOfLive) % this->through)) {
    // std::cout << "wtf";
    create();
  }
}

void Prey::printInfo() {
  std::cout << "S";
}
