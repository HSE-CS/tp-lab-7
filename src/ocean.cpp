// Copyright 2021 Galex

#include "../include/ocean.h"
#include "../include/stone.h"
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/common.h"

Ocean::Ocean() {
  unsigned int seed = time(nullptr);

  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLUMNS; ++j) {
      Pair p;
      p.x = i;
      p.y = j;
      this->cells[i][j] = new Cell(p, this);
    }
  }

  while (this->numOfStones < STONES_INIT_NUMBER) {
    int randX = rand_r(&seed) % ROWS;
    int randY = rand_r(&seed) % COLUMNS;
    if (this->cells[randX][randY]->isFree()) {
      this->cells[randX][randY]->
          setObject(new Stone(this->cells[randX][randY]));
      this->numOfStones++;
      stuff.push_back(this->cells[randX][randY]->getObject());
    }
  }
  while (this->numOfPreys < PREYS_INIT_NUMBER) {
    int randX = rand_r(&seed) % ROWS;
    int randY = rand_r(&seed) % COLUMNS;
    if (this->cells[randX][randY]->isFree()) {
      this->cells[randX][randY]->
          setObject(new Prey(this->cells[randX][randY]));
      this->numOfPreys++;
      stuff.push_back(this->cells[randX][randY]->getObject());
    }
  }
  while (this->numOfPredators < PREDATORS_INIT_NUMBER) {
    int randX = rand_r(&seed) % ROWS;
    int randY = rand_r(&seed) % COLUMNS;
    if (this->cells[randX][randY]->isFree()) {
      this->cells[randX][randY]->
      setObject(new Predator(this->cells[randX][randY]));
      this->numOfPredators++;
      stuff.push_back(this->cells[randX][randY]->getObject());
    }
  }
}
void Ocean::print() const {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLUMNS; ++j) {
      if (this->cells[i][j]->getObject() != nullptr) {
        std::cout << this->cells[i][j]->getObject()->getOutput();
      } else {
        std::cout << "\033[96;106mO\033[0m";
      }
    }
    std::cout << "\n";
  }
}
void Ocean::addObject(Object *o) {
  switch (o->getType()) {
    case TYPE::PREDATOR:numOfPredators++;
    case TYPE::PREY:numOfPreys++;
  }
  stuff.push_back(o);
}
void Ocean::removeObject(Object *o) {
  stuff.remove(o);
}
void Ocean::run() {
  while (numOfPredators > 0 && numOfPreys > 0) {
    for (auto const &i : stuff) {
      i->live();
    }
    this->print();
    std::cout << "Num of Preys - " << this->numOfPreys <<
              " Num of Predators - " << this->numOfPredators << "\n";
  }
}
