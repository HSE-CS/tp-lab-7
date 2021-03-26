// Copyright 2020 Uskova

#include <chrono>
#include <thread>
#include "ocean.h"

Ocean::Ocean() {
    this->cells = new Cell*[N];
    for (int i = 0; i < N; ++i) {
        cells[i] = new Cell[M];
    }
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) {
          this->cells[i][j].init(Pair{i, j}, this);
      }
    std::list<Object*> inhabitants;
    this->stuff = inhabitants;
}

Ocean::~Ocean() {
    for (int i = 0; i < N; ++i) {
        delete this->cells[i];
    }
    delete[] this->cells;
    this->stuff.erase(this->stuff.begin(), this->stuff.end());
}

void Ocean::print() const {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      Object* object = this->cells[i][j].getObject();
      if (object != nullptr && object->getType() != ObjType::EMPTY) {
        std::cout << this->cells[i][j].getObject()->getObjSym();
      } else {
        std::cout << EMPTY_N;
      }
    }
    std::cout << std::endl;
  }
}

Cell** Ocean::getOcean() {
    return this->cells;
}

void Ocean::createLife() {
  srand(time(0));
  int predators = PREDATORS * N * M;
  int preys = PREYS * N * M;
  int stones = STONES * N * M;
  int flag = 1;
  for (int i = 0; i < stones; ++i) {
    flag = 1;
    while (flag == 1) {
      int x = rand() % N;
      int y = rand() % M;
      if (this->cells[x][y].obj == nullptr) {
        flag = 0;
        Object* stone = new Stone(&this->cells[x][y], ObjType::STONE);
        this->cells[x][y].setObject(stone);
        stuff.push_back(stone);
      }
    }
  }
  for (int i = 0; i < preys; ++i) {
    flag = 1;
    while (flag == 1) {
      int x = rand() % N;
      int y = rand() % M;
      if (this->cells[x][y].obj == nullptr) {
        flag = 0;
        Object* prey = new Prey(&this->cells[x][y], ObjType::PREY);
        this->cells[x][y].obj = prey;
        stuff.push_back(prey);
      }
    }
  }
  for (int i = 0; i < predators; ++i) {
    flag = 1;
    while (flag == 1) {
      int x = rand() % N;
      int y = rand() % M;
      if (this->cells[x][y].obj == nullptr) {
        flag = 0;
        Object* predator = new Predator(&this->cells[x][y], ObjType::PREDATOR);
        this->cells[x][y].obj = predator;
        stuff.push_back(predator);
      }
    }
  }
}

void Ocean::cleanDeleteList() {
  for (auto& obj : this->forDeleting) {
    this->stuff.remove(obj);
    delete obj;
  }
  this->forDeleting.clear();
}

void Ocean::addObject(Object* obj) {
    this->stuff.push_back(obj);
}

void Ocean::inDeleteList(Object* obj) {
    this->forDeleting.push_back(obj);
}

void Ocean::run() {
  int flag1 = 0, flag2 = 0;
  std::vector<Object*> forDeleting;
  while (true) {
    for (Object* obj : stuff) {
      if (obj != nullptr) {
        if (obj->getType() != ObjType::EMPTY) {
          obj->live();
          if (obj != nullptr) {
            if (obj->getType() == ObjType::PREY) {
              flag1 = 1;
            }
            if (obj->getType() == ObjType::PREDATOR) {
              flag2 = 1;
            }
          }
        }
      }
    }
    this->cleanDeleteList();
    system("cls");
    this->print();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (flag1 == 0 || flag2 == 0) {
      exit(0);
    }
    flag1 = 0;
    flag2 = 0;
  }
}
