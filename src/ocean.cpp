//// Copyright 2021 Ozhiganova Polina
#include <zconf.h>
#include <random>
#include "../include/ocean.h"
static std::mt19937_64 rng;

/* OCEAN */
Ocean::Ocean() {
  this->cells = new Cell *[M];
  for (int i = 0; i < M; ++i) {
    cells[i] = new Cell[N];
    for (int j = 0; j < N; ++j) {
      cells[i][j].init(Pair({static_cast<coord_t>(i),
                             static_cast<coord_t>(j)}),
                       this);
    }
  }
}

Ocean::~Ocean() {
  for (int i = 0; i < M; i++) {
    delete[] cells[i];
  }
  delete[] cells;
}

void Ocean::fullHouse(float preyPerc,
                      float predatorPerc,
                      float stonePerc) {
  int preyAmount = static_cast<int>(preyPerc * M * N);
  for (int i = 0; i < preyAmount; ++i) {
    while (true) {
      int x = static_cast<int>(rng() % M);
      int y = static_cast<int>(rng() % N);
      if (cells[x][y].obj == nullptr) {
        Object *newPrey = new Prey
            (ObjType::PREY, &cells[x][y]);
        cells[x][y].obj = newPrey;
        stuff.push_back(newPrey);
        break;
      }
    }
  }
  int predatorAmount = static_cast<int>(predatorPerc * M * N);
  for (int i = 0; i < predatorAmount; ++i) {
    while (true) {
      int x = static_cast<int>(rng() % M);
      int y = static_cast<int>(rng() % N);
      if (cells[x][y].obj == nullptr) {
        Object *newPredator = new Predator
            (ObjType::PREDATOR, &cells[x][y]);
        cells[x][y].obj = newPredator;
        stuff.push_back(newPredator);
        break;
      }
    }
  }
  int stoneAmount = static_cast<int>(stonePerc * M * N);
  for (int i = 0; i < stoneAmount; ++i) {
    while (true) {
      int x = static_cast<int>(rng() % M);
      int y = static_cast<int>(rng() % N);
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

Cell **Ocean::getMatrix() {
  return this->cells;
}

void Ocean::print() const {
//  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      Object *object = cells[i][j].getObject();
      if (object == nullptr) {
      // SetConsoleTextAttribute(hConsole, 9);
        std::cout << BLUE << EMPTY_N << RESET;
      } else {
        ObjType type = object->getObjType();
        if (type == ObjType::PREY) {
        //  SetConsoleTextAttribute(hConsole, 14);
          std::cout << YELLOW << PREY_N << RESET;
        } else if (type == ObjType::PREDATOR) {
        //  SetConsoleTextAttribute(hConsole, 13);
          std::cout << RED << PREDATOR_N << RESET;
        } else if (type == ObjType::STONE) {
        //  SetConsoleTextAttribute(hConsole, 8);
          std::cout << GREEN << STONE_N << RESET;
        } else if (type == ObjType::EMPTY) {
        //  SetConsoleTextAttribute(hConsole, 9);
          std::cout << BLUE << EMPTY_N << RESET;
        }
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void Ocean::addObjects(Object *newObj) {
  stuff.push_back(newObj);
}

void Ocean::delObjects() {
  for (auto &obj : toDeleteCreatures) {
    stuff.remove(obj);
    delete obj;
  }
  toDeleteCreatures.clear();
}

void Ocean::addDeleteCreatures(Object *obj) {
  toDeleteCreatures.push_back(obj);
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
    this->delObjects();
    this->print();
    sleep(1);
    if (count == 0) {
      exit(0);
    }
    count = 0;
  }
}





