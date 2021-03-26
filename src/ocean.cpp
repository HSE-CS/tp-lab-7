// Copyright 2021 Elise
#include "ocean.h"

#include <ctime>
#include <iostream>
#include <vector>


Ocean::Ocean(int X, int Y, int number) {
  this->X = X;
  this->Y = Y;
  cells = new Cell*[X];
  for (int i = 0; i < X; i++) {
    cells[i] = new Cell[Y];
    for (int j = 0; j < Y; j++) {
      cells[i][j].init(Pair{i, j}, this);
    }
  }
  addObjects(number);
}

void Ocean::addObjects(int number) {
  for (int i = 0; i < number; i++) {
    int seed = time(nullptr);
    int x_ = rand_r(&seed) % X;
    int y_ = rand_r(&seed) % Y;
    int prbb = rand_r(&seed) % 100;
    if (this->cells[x_][y_].getObject()) {
      continue;
    }
    Object* obj = nullptr;
    if (prbb > 70) {
      obj = new Predator(&cells[x_][y_]);
    } else if ((prbb <= 70) &&
               (prbb >= 50)) {
      obj = new Stone(&cells[x_][y_]);
    } else if (prbb < 50) {
      obj = new Prey(&cells[x_][y_]);
    }
    this->cells[x_][y_].setObject(obj);
    this->stuff.push_back(obj);
  }
}

void Ocean::print() const {
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
      if (!cells[i][j].getObject()) {
        std::cout << '.';
      } else {
        std::cout << cells[i][j].getObject()->get_type();
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl << std::endl;
}

Cell* Ocean::coordinates(Pair crd) {
   std::vector<Cell*> new_cells;
  for (int i = crd.x_ - 1; i <= crd.x_ + 1; i++) {
    for (int j = crd.y_ - 1; j <= crd.y_ + 1; j++) {
      if (i >= 0 && i < X && j >= 0 && j < Y) {
        if (!this->cells[i][j].getObject()) {
          new_cells.push_back(&cells[i][j]);
        }
      }
    }
  }
  if (new_cells.empty()) {
    return nullptr;
  } else {
    return new_cells[rand() % new_cells.size()];
  }
}

void Ocean::run() {
  this->print();
  while (!this->stuff.empty()) {
    for (auto& obj : this->stuff) {
      obj->live();
    }
    for (auto& i : this->l_d) {
      this->stuff.remove(i);
      i->setCell(nullptr);
    }
    l_d.clear();
    print();
  }
}

void Ocean::addObject(Object* object_new) {
    stuff.push_back(object_new);
}

void Ocean::AddListOfTheDead(Object* object_new) {
  if (object_new) {
    l_d.push_back(object_new);
  }
}


Cell* Ocean::lets_go_eat(Pair coordinate) {
  std::vector<Cell*> cells_prey;
  for (size_t i = coordinate.x_ - 1; i <= coordinate.x_ + 1; i++) {
    for (size_t j = coordinate.y_ - 1; j <= coordinate.y_ + 1; j++) {
      if (i >= 0 && i < X && j >= 0 && j < Y) {
        if (this->cells[i][j].getObject()) {
          if (cells[i][j].getObject()->get_type() == PREY_N) {
            cells_prey.push_back(&this->cells[i][j]);
          }
        }
      }
    }
  }
  if (!cells_prey.empty()) {
    return cells_prey[rand() % cells_prey.size()];
  } else {
    return nullptr;
  }
}

Ocean::~Ocean() {
  for (int i = 0; i < Y; i++) {
    delete[] cells[i];
  }
  delete[] cells;
  for (auto i = stuff.begin(); i != stuff.end(); i++) {
    delete *i;
  }
}