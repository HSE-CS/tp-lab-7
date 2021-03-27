// Copyright 2021 Smirnov Grigory
#include "../include/ocean.h"
#include <random>
#include <iostream>

Ocean::Ocean(size_t n, size_t m) {
  cells = new Cell * [n];
  for (unsigned i = 0; i < n; i++)
    cells[i] = new Cell[m];
  this->n = n;
  this->m = m;
  for (unsigned i = 0; i < n; i++)
    for (unsigned j = 0; j < m; j++)
      cells[i][j].init({ i, j }, this);
}

Ocean::~Ocean() {
  for (int i = 0; i < n; i++)
    delete[] cells[i];
  delete[] cells;
}

void Ocean::fillType(int number, char type) {
  if (!(type == STONE_N || type == PREY_N || type == PREDATOR_N))
    return;
  std::random_device seed;
  while (number > 0) {
    int i = seed() % n;
    int j = seed() % m;
    if (cells[i][j].obj == nullptr) {
      Object* o;
      if (type == STONE_N)
        o = new Stone(&cells[i][j]);
      if (type == PREY_N)
        o = new Prey(&cells[i][j]);
      if (type == PREDATOR_N)
        o = new Predator(&cells[i][j]);
      addObj(o);
      cells[i][j].setObject(o);
      number--;
    }
  }
}

void Ocean::fillAll(int stones, int preys, int predators) {
  if ((stones + preys + predators) > n * m * 0.8)
    return;
  fillType(stones, STONE_N);
  fillType(preys, PREY_N);
  fillType(predators, PREDATOR_N);
}

void Ocean::addObj(Object* o) {
  stuff.push_back(o);
}

void Ocean::run() {
  for (int i = 0; i < stuff.size(); i++)
    stuff[i]->live();
  for (int i = 0; i < stuff.size(); i++)
    if (stuff[i]->getStatus() == DEAD) {
      stuff.erase(stuff.begin() + i);
    }
}

void Ocean::print() const {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cells[i][j].getObject() == nullptr)
        std::cout << NOTHING_N;
      else
        std::cout << cells[i][j].getObject()->getType();
    }
    std::cout << std::endl;
  }
}

size_t Ocean::getN() {
  return n;
}

size_t Ocean::getM() {
  return m;
}
