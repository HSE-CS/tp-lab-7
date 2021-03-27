// Copyright 2021 Lab_7 TiNa
#include <ctime>
#include <iostream>
#include <vector>

#include "common.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"
#include "ocean.h"

Ocean::Ocean() {
  cells = new Cell*[M];
  for (int i = 0; i < M; i++) {
    cells[i] = new Cell[N];
    for (int j = 0; j < N; j++) {
      cells[i][j].init(Pair{i, j}, this);
    }
  }
}

void Ocean::print() const {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (cells[i][j].getObject() == nullptr) {
        std::cout << ".";
      } else if (cells[i][j].getObject()->getType() == STONE) {
        std::cout << STONE_N;
      } else if (cells[i][j].getObject()->getType() == PREDATOR) {
        std::cout << PREDATOR_N;
      } else if (cells[i][j].getObject()->getType() == PREY) {
        std::cout << PREY_N;
      }
    }
    std::cout << std::endl;
  }
}

void Ocean::addObjects(int num_of_obj) { 
  for (int i = 0; i < num_of_obj; i++) {
    srand(time(0));
    int x = rand() % M;
    int y = rand() % N;
    int prob = rand() % 100;
    if (cells[x][y].getObject()) {
      continue;
    } else {
      Object* obj = nullptr;
      if (prob < 33) {
        obj = new Prey(&cells[x][y]);
      } else if ((prob >= 33) && (prob <= 66)) {
        obj = new Stone(&cells[x][y]);
      } else if (prob > 66) {
        obj = new Predator(&cells[x][y]);
      }
      cells[x][y].setObject(obj);
      stuff.push_back(obj);
    }
  }
}

void Ocean::addObjects(Object* objIn) { stuff.push_back(objIn); }

void Ocean::run() {
  while (true) {
    for (Object* obj : stuff) {
      obj->live();
    }
    print();
  }
}

Cell* Ocean::eat(Pair cor) {
  std::vector<Cell*> preyC;
  for (int i = cor.x - 1; i <= cor.x + 1; i++) {
    for (int j = cor.y - 1; j <= cor.y + 1; j++) {
      if ((i >= 0) && (i < M) && (j >= 0) && (j < N)) {
        if (cells[i][j].getObject()) {
          if (cells[i][j].getObject()->getType() == PREY_N) {
            preyC.push_back(&cells[i][j]);
          }
        }
      }
    }
  }
  if (!preyC.empty()) {
    return preyC[rand() % preyC.size()];
  } else {
    return nullptr;
  }
}

Cell* Ocean::find(Pair cor) {
  std::vector<Cell*> emptC;
  for (int i = cor.x - 1; i <= cor.x + 1; i++) {
    for (int j = cor.y - 1; j <= cor.y + 1; j++) {
      if ((i >= 0) && (i < M) && (j >= 0) && (j < N)) {
        if (!cells[i][j].getObject()) {
          emptC.push_back(&cells[i][j]);
        }
      }
    }
  }
  if (!emptC.empty()) {
    return emptC[rand() % emptC.size()];
  } else {
    return nullptr;
  }
}

Ocean::~Ocean() {
  for (int i = 0; i < N; i++) {
    delete[] cells[i];
  }
  delete[] cells;
  for (Object* i : stuff) {
    delete i;
  }
}
