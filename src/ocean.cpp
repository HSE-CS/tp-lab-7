// Copyright 2021 Egor Buzanov

#include "../include/ocean.h"

#include "../include/cell.h"
#include "../include/common.h"
#include "../include/object.h"
#include "../include/predator.h"
#include "../include/prey.h"
#include "../include/stone.h"

Ocean::Ocean(unsigned int _M, unsigned int _N) {
  M = _M;
  N = _N;
  std::random_device rd;
  std::mt19937 mersenne(rd());
  int randomizer = 0;
  cells = new Cell *[M];
  for (int i = 0; i < M; i++) {
    cells[i] = new Cell[N];
    for (int j = 0; j < N; j++) {
      Cell new_cell({i, j}, this);
      cells[i][j] = new_cell;
      randomizer = mersenne() % 4;
      if (randomizer == 0) {
        objects.push_back(new Stone(&cells[i][j]));
        cells[i][j].setObject(objects.back());
      } else if (randomizer == 1) {
        objects.push_back(new Prey(&cells[i][j]));
        cells[i][j].setObject(objects.back());
      } else if (randomizer == 2) {
        objects.push_back(new Predator(&cells[i][j]));
        cells[i][j].setObject(objects.back());
      }
    }
  }
}

void Ocean::print() const {
  for (size_t i = 0; i < M; i++) {
    for (size_t j = 0; i < N; j++) {
      if (cells[i][j].obj != nullptr) {
        std::cout << ".";
      } else if (cells[i][j].obj->getType() == STONE) {
        std::cout << STONE_N;
      } else if (cells[i][j].obj->getType() == PREY) {
        std::cout << PREY_N;
      } else if (cells[i][j].obj->getType() == PREDATOR) {
        std::cout << PREDATOR_N;
      }
    }
    std::cout << std::endl;
  }
}

void Ocean::AddObject(Object *_obj) {
  for (size_t i = 0; i < M; i++) {
    for (size_t j = 0; j < N; j++) {
      if (cells[i][j].getObject() == nullptr) {
        cells[i][j].setObject(_obj);
        _obj->setCell(&cells[i][j]);
        return;
      }
    }
  }
}

void Ocean::run() {
  int prey_count = 0;
  int predator_count = 0;
  while (true) {
    for (auto &obj : objects) {
      obj->live();
      if (obj->getType() == PREDATOR) {
        ++predator_count;
      }
      if (obj->getType() == PREY) {
        ++prey_count;
      }
    }
    print();
    if (prey_count < 1 || predator_count < 1) {
      break;
    }
    prey_count = 0;
    predator_count = 0;
  }
}

void Ocean::deleteObject(Object *_obj) { objects.remove(_obj); }

void Ocean::objectStep(Cell *_cell) {
  std::random_device rd;
  std::mt19937 mersenne(rd());
  int randomizer = 0;
  int i = _cell->crd.x;
  int j = _cell->crd.y;
  if (cells[i][j].obj->getType() == PREY) {
    for (size_t l = 0; l < 6; l++) {
      randomizer = mersenne() % 4 + 1;
      if (randomizer == 1 && i > 0 && j > 0 &&
          cells[i - 1][j - 1].obj == nullptr) {
        cells[i - 1][j - 1].obj = _cell->getObject();
        _cell->obj->setCell(&cells[i - 1][j - 1]);
        _cell->obj = nullptr;
      } else if (randomizer == 2 && i < M - 1 && j < N - 1 &&
                 cells[i + 1][j + 1].obj == nullptr) {
        cells[i + 1][j + 1].obj = _cell->getObject();
        _cell->obj->setCell(&cells[i + 1][j + 1]);
        _cell->obj = nullptr;
      } else if (randomizer == 3 && i < M - 1 && j > 0 &&
                 cells[i + 1][j - 1].obj == nullptr) {
        cells[i + 1][j - 1].obj = _cell->getObject();
        _cell->obj->setCell(&cells[i + 1][j - 1]);
        _cell->obj = nullptr;
      } else if (randomizer == 4 && i > 0 && j < N - 1 &&
                 cells[i - 1][j + 1].obj == nullptr) {
        cells[i - 1][j + 1].obj = _cell->getObject();
        _cell->obj->setCell(&cells[i - 1][j + 1]);
        _cell->obj = nullptr;
      }
    }
  } else {
    for (size_t l = 0; l < 6; l++) {
      randomizer = mersenne() % 4 + 1;
      if (randomizer == 1 && i > 0 && j > 0 &&
          cells[i - 1][j - 1].obj->getType() != STONE &&
          cells[i - 1][j - 1].obj->getType() != PREDATOR) {
        if (cells[i - 1][j - 1].obj->getType() == PREY) {
          cells[i - 1][j - 1].killMe();
          (reinterpret_cast<Predator *>(_cell->obj))->refreshFeed();
        }
        cells[i - 1][j - 1].obj = _cell->getObject();
        _cell->obj->setCell(&cells[i - 1][j - 1]);
        _cell->obj = nullptr;
      } else if (randomizer == 2 && i < M - 1 && j < N - 1 &&
                 cells[i + 1][j + 1].obj->getType() != STONE &&
                 cells[i + 1][j + 1].obj->getType() != PREDATOR) {
        if (cells[i + 1][j + 1].obj->getType() == PREY) {
          cells[i + 1][j + 1].killMe();
          (reinterpret_cast<Predator *>(_cell->obj))->refreshFeed();
        }
        cells[i + 1][j + 1].obj = _cell->getObject();
        _cell->obj->setCell(&cells[i + 1][j + 1]);
        _cell->obj = nullptr;
      } else if (randomizer == 3 && i < M - 1 && j > 0 &&
                 cells[i + 1][j - 1].obj->getType() != STONE &&
                 cells[i + 1][j - 1].obj->getType() != PREDATOR) {
        if (cells[i + 1][j - 1].obj->getType() == PREY) {
          cells[i + 1][j - 1].killMe();
          (reinterpret_cast<Predator *>(_cell->obj))->refreshFeed();
        }
        cells[i + 1][j - 1].obj = _cell->getObject();
        _cell->obj->setCell(&cells[i + 1][j - 1]);
        _cell->obj = nullptr;
      } else if (randomizer == 4 && i > 0 && j < N - 1 &&
                 cells[i - 1][j + 1].obj->getType() != STONE &&
                 cells[i - 1][j + 1].obj->getType() != PREDATOR) {
        if (cells[i - 1][j + 1].obj->getType() != PREY) {
          cells[i - 1][j + 1].killMe();
          (reinterpret_cast<Predator *>(_cell->obj))->refreshFeed();
        }
        cells[i - 1][j + 1].obj = _cell->getObject();
        _cell->obj->setCell(&cells[i - 1][j + 1]);
        _cell->obj = nullptr;
      }
    }
  }
}
