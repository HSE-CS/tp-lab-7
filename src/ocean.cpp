// Copyright NikDemoShow 2021
#include"ocean.h"
#include"prey.h"
#include"stone.h"
#include"cell.h"
#include"predator.h"
#include<iostream>
#include<windows.h>
#include<algorithm>
Ocean::Ocean() { 
  this->cells = new Cell*[M];
  for (size_t i{0}; i < M; ++i) {
    cells[i] = new Cell[N];
    for (size_t j{0}; j < N; ++j) {
      int chooseNewObj{std::rand() % 100 + 1};
      Object* newObj{nullptr};
      if (chooseNewObj <= prPrey) {
        newObj = new Prey();
      }
      else if (chooseNewObj <= prPrey + prStone) {
        newObj = new Stone();
      }
      else if (chooseNewObj <= prPrey + prStone + prPredator) {
        newObj = new Predator();
      }
      cells[i][j] = Cell({i, j}, this, newObj);
      if (newObj) {
        newObj->setCell(&cells[i][j]);
        this->stuff.push_back(newObj);
      }
    }
  }
  std::random_shuffle(this->stuff.begin(), this->stuff.end());
}
Ocean::~Ocean() {
  for (std::vector<Object*>::iterator it = this->stuff.begin(); it != this->stuff.end();) {
    delete* it;
    it = this->stuff.erase(it);
  }
  for (size_t i{ 0 }; i < M; ++i) {
    delete[] this->cells[i];
  }
  delete[] this->cells;
}
Cell* Ocean::getCell(const size_t x, const size_t y) {return &this->cells[x][y]; }
void Ocean::addObject(const ObjType type, Cell* newCell) {
  Object* newObj{ nullptr };
  switch (type) {
  case (ObjType::PREY):
    newObj = new Prey();
    break;
  case (ObjType::PREDATOR):
    newObj = new Predator();
    break;
  }
  if (newObj) {
    newObj->setCell(newCell);
    newCell->setObject(newObj);
    this->tempStuff.push_back(newObj);
  }
}
void Ocean::addObjects() {
  for (Object* obj : this->tempStuff) {
    this->stuff.push_back(obj);
  }
  this->tempStuff.clear();
}
void Ocean::delObjects() {
  for (std::vector<Object*>::iterator it = this->stuff.begin(); it != this->stuff.end();) {
    if (!(*it)->getCell()) {
      delete* it;
      it = this->stuff.erase(it);
    }
    else {
      ++it;
    }
  }
}
void Ocean::print() const {
  for (size_t i{0}; i < M; ++i) {
    for (size_t j{0}; j < N; ++j) {
      if (this->cells[i][j].getObject()) {
        ObjType currObj{this->cells[i][j].getObjectType()};
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
      }
      else {
        std::cout << '.';
      }
    }
    std::cout << std::endl;
  }
}
void Ocean::run() {
  while (true) {
    this->delObjects();
    this->print();
    unsigned int cPredator{ 0 }, cPrey{ 0 };
    for (Object* obj : this->stuff) {
      if (obj->getCell()->getObjectType() == ObjType::PREY) {
        cPrey++;
      }
      else if (obj->getCell()->getObjectType() == ObjType::PREDATOR) {
        cPredator++;
      }
    }
    if (!cPredator) {
      break;
    }
    Sleep(1000);
    system("CLS");
    for (Object* obj : this->stuff) {
      if (obj->getCell()) {
        obj->live();
      }
    }
    this->addObjects();
  }
}
