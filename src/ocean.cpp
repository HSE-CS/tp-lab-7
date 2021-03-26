// Copyright DB 2021

#include "ocean.h"
#include "common.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"
#include "cell.h"

#include <stdlib.h>
#include <algorithm>
#include <ctime>
#include <vector>

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

void Ocean::generateWorld(int nstones, int ncorals,
                          int npreys, int npredators) {
  Pair p{0, 0};
  for (size_t i = 0; i < nstones; i++) {
    Stone* tstone = new Stone;
    while (this->getCell(p)->getObject() != nullptr) {
      p.x_cord = (rand() % (N - 1)) + 1;
      p.y_cord = (rand() % (M - 1)) + 1;
    }
    this->addObject(tstone);
    Cell* cell = this->getCell(p);
    tstone->init(cell);
    cell->setObject(tstone);
  }
  for (size_t i = 0; i < ncorals; i++) {
    Coral* ncoral = new Coral;
    while (this->getCell(p)->getObject() != nullptr) {
      p.x_cord = (rand() % (N - 1)) + 1;
      p.y_cord = (rand() % (M - 1)) + 1;
    }
    this->addObject(ncoral);
    Cell* cell = this->getCell(p);
    ncoral->init(cell);
    cell->setObject(ncoral);
  }
  for (size_t i = 0; i < npreys; i++) {
    Prey* nprey = new Prey;
    while (this->getCell(p)->getObject() != nullptr) {
      p.x_cord = (rand() % (N - 1)) + 1;
      p.y_cord = (rand() % (M - 1)) + 1;
    }
    this->addObject(nprey);
    Cell* cell = this->getCell(p);
    nprey->init(cell);
    cell->setObject(nprey);
  }
  for (size_t i = 0; i < npredators; i++) {
    Predator* npredator = new Predator;
    while (this->getCell(p)->getObject() != nullptr) {
      p.x_cord = (rand() % (N - 2)) + 1;
      p.y_cord = (rand() % (M - 2)) + 1;
    }
    this->addObject(npredator);
    Cell* cell = this->getCell(p);
    npredator->init(cell);
    cell->setObject(npredator);
  }
}

void Ocean::addObject(Object* obj) { this->objects.push_back(obj); }

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
    std::cout << "\n\n\n\n\n" << std::endl;
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