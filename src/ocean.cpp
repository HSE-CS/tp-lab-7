// Copyright GN 2021
#include <vector>
#include <ctime>
#include "../include/common.h"
#include "../include/ocean.h"

Ocean::Ocean() {
  this->cells = new Cell*[N];
  for (int i = 0; i < N; i++) {
    cells[i] = new Cell[M];
    for (int j = 0; j < M; j++) {
      Pair* time_pair = new Pair;
      time_pair->x_cord = i;
      time_pair->y_cord = j;
      cells[i][j].init(*time_pair, this);
    }
  }
}
Cell* Ocean::getCell(Pair p) { return &this->cells[p.x_cord][p.y_cord]; }
void Ocean::generateWorld(int number_of_preys, int number_of_predators,
    int number_of_stones, int number_of_corals) {
  srand(std::time(0));
  Pair p{0, 0};
  for (size_t i = 0; i < number_of_preys; i++) {
    Prey* new_prey = new Prey;
    while (this->getCell(p)->getObject() != nullptr) {
      p.x_cord = (rand_r() % (N - 1)) + 1;
      p.y_cord = (rand_r() % (M - 1)) + 1;
    }
    this->addObject(new_prey);
    Cell* cell = this->getCell(p);
    new_prey->init(cell);
    cell->setObject(new_prey);
  }
  for (size_t i = 0; i < number_of_predators; i++) {
    Predator* new_predator = new Predator;
    while (this->getCell(p)->getObject() != nullptr) {
      p.x_cord = (rand_r() % (N - 2)) + 1;
      p.y_cord = (rand_r() % (M - 2)) + 1;
    }
    this->addObject(new_predator);
    Cell* cell = this->getCell(p);
    new_predator->init(cell);
    cell->setObject(new_predator);
  }
  for (size_t i = 0; i < number_of_stones; i++) {
    Stone* time_stone = new Stone;
    while (this->getCell(p)->getObject() != nullptr) {
      p.x_cord = (rand_r() % (N - 1)) + 1;
      p.y_cord = (rand_r() % (M - 1)) + 1;
    }
    this->addObject(time_stone);
    Cell* cell = this->getCell(p);
    time_stone->init(cell);
    cell->setObject(time_stone);
  }
  for (size_t i = 0; i < number_of_corals; i++) {
    Coral*new_coral = new Coral;
    while (this->getCell(p)->getObject() != nullptr) {
      p.x_cord = (rand_r() % (N - 1)) + 1;
      p.y_cord = (rand_r() % (M - 1)) + 1;
    }
    this->addObject(new_coral);
    Cell* cell = this->getCell(p);
    new_coral->init(cell);
    cell->setObject(new_coral);
  }
}

void Ocean::run() {
  while (1) {
    size_t number_of_prey = 0;
    size_t number_of_predator = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (cells[i][j].getObject() != nullptr) {
          if (cells[i][j].getObject()->getObjectINT() == 2) number_of_prey++;
          if (cells[i][j].getObject()->getObjectINT() == 3)
            number_of_predator++;
        }
      }
    }
    if (number_of_prey == 0) {
      std::cout << "There is no prey in the ocean" << std::endl;
      break;
    }
    if (number_of_predator == 0) {
      std::cout << "There are no predators in the ocean" << std::endl;
      break;
    }
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
                 "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
                 "++++++++++++++++++++++++++++++++++"
              << std::endl;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (cells[i][j].getObject() != nullptr) {
          cells[i][j].getObject()->live();
        }
      }
    }
    this->print();
  }
}
void Ocean::addObject(Object* obj) { this->objects.push_back(obj); }
void Ocean::print() const {
  std::string str;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      if (cells[i][j].getObject() == nullptr)
        str += '.';
      else
        str += cells[i][j].getObject()->getObjectChar();
    }
    str += '\n';
  }
  std::cout << str;
}
