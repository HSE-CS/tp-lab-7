// Copyright TimurZaytsev 2021
#include "ocean.h"

#include <algorithm>
#include <iostream>

#include "cell.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"
Ocean::Ocean() {
  this->cells = new Cell*[M];
  for (unsigned int i{0}; i < M; i++) {
    cells[i] = new Cell[N];
    for (unsigned int k{0}; k < N; k++) {
      int ChNewObject{std::rand() % 100 + 1};
      Object* newObj{nullptr};
      if (ChNewObject <= prPrey) {
        newObj = new Prey();
      } else if (ChNewObject <= prPrey + prStone) {
        newObj = new Stone();
      } else if (ChNewObject <= prPrey + prStone + prPredator) {
        newObj = new Predator();
      }
      cells[i][k] = Cell({i, k}, this, newObj);
      if (newObj) {
        newObj->set(&cells[i][k]);
        this->s.push_back(newObj);
      }
    }
  }
  std::random_shuffle(this->s.begin(), this->s.end());
}
Ocean::~Ocean() {
  for (std::vector<Object*>::iterator it = this->s.begin();
       it != this->s.end();) {
    delete *it;
    it = this->s.erase(it);
  }
  for (unsigned int i{0}; i < M; i++) {
    delete[] this->cells[i];
  }
  delete[] this->cells;
}
Cell* Ocean::getCell(const unsigned int x, const unsigned int y) {
  return &this->cells[x][y];
}
void Ocean::addObj(const ObjType type, Cell* newCell) {
  Object* newObj{nullptr};
  switch (type) {
    case (ObjType::PREY):
      newObj = new Prey();
      break;
    case (ObjType::PREDATOR):
      newObj = new Predator();
      break;
  }
  if (newObj) {
    newObj->set(newCell);
    newCell->setObj(newObj);
    this->tempOfStuff.push_back(newObj);
  }
}
void Ocean::addObj() {
  for (Object* obj : this->tempOfStuff) {
    this->s.push_back(obj);
  }
  this->tempOfStuff.clear();
}
void Ocean::delObj() {
  for (std::vector<Object*>::iterator it = this->s.begin();
       it != this->s.end();) {
    if (!(*it)->getCell()) {
      delete *it;
      it = this->s.erase(it);
    } else {
      it++;
    }
  }
}
void Ocean::print() const {
  for (unsigned int i{0}; i < M; i++) {
    for (unsigned int k{0}; k < N; k++) {
      if (this->cells[i][k].getObj()) {
        ObjType currObj{this->cells[i][k].getObjType()};
        switch (currObj) {
          case (ObjType::PREY):
            std::cout << PREY_N;
            break;
          case (ObjType::STONE):
            std::cout << STONE_N;
            break;
          case (ObjType::PREDATOR):
            std::cout << PREDATOR_N;
            break;
          default:
            std::cout << '.';
        }
      } else {
        std::cout << '.';
      }
    }
    std::cout << std::endl;
  }
}
void Ocean::go() {
  while (true) {
    this->delObj();
    this->print();
    unsigned int cPr{0}, cPrey{0};
    for (Object* obj : this->s) {
      if (obj->getCell()->getObjType() == ObjType::PREY) {
        cPrey++;
      } else if (obj->getCell()->getObjType() == ObjType::PREDATOR) {
        cPr++;
      }
    }
    if (!cPr) {
      break;
    }
    if (system("CLS")) {
    }
    for (Object* obj : this->s) {
      if (obj->getCell()) {
        obj->live();
      }
    }
    this->addObj();
  }
}
