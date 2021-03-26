// Copyright 2021 Schenikova

#include "../include/ocean.h"
#include <random>
// #include <system>

Ocean::Ocean() {
  this->cells = new Cell*[N];
  for (size_t i = 0; i < N; i++) {
    this->cells[i] = new Cell[M];
    for (size_t j = 0; j < M; j++)
      this->cells[i][j].init(Pair(i, j), this);
  }
}

Ocean::~Ocean() {
  for (size_t i = 0; i < N; i++) {
    delete[] this->cells[i];
  }
  delete this->cells;
}

void Ocean::print() {
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      if (!this->cells[i][j].getObject()) {
        std::cout << ".";
        continue;
      }
      this->cells[i][j].getObject()->printInfo();
    }
    std::cout << std::endl;
  }
}

void Ocean::addObjects(std::vector<Object*> objects) {
  int i, j;
  std::minstd_rand simple_rand;
  simple_rand.seed(55);
  for (auto o : objects) {
    i = simple_rand() % N;
    j = simple_rand() % M;
    stuff.push_back(o);
    this->cells[i][j].setObject(o);
  }
}

void Ocean::run() {
  while (true) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (this->cells[i][j].getObject()) {
          if (this->cells[i][j].getObject()->IsPrey())
            countPrey++;
          if (this->cells[i][j].getObject()->IsPredator())
            countPredator++;
          this->cells[i][j].getObject()->live();
        }
      }
    }
    if (!countPrey) {
      std::cout << "All Preys are died\n";
      return;
    }
    if (!countPredator) {
      std::cout << "All Predators are died\n";
      return;
    }
    countPredator = 0;
    countPrey = 0;
  // system("clear");
  print();
  sleep(1);
  // delObj();
  }
}

// void Ocean::delObj() {
//   for (auto o : delList)
//     for (auto i = stuff.begin(); i != stuff.end(); i++) {
//       if (o == (*i)) {
//         stuff.erase(i);
//         return;
//       }
//     }
//     delList.clear();
// }

// void Ocean::addToList(Object* obj) {
//   delList.push_back(obj);
// }


