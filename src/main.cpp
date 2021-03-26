// Copyright 2020 S. BOR

#include "predator.h"
#include "prey.h"
#include "stone.h"
#include "ocean.h"
#include <random>

int main() {
  Ocean* ocean = new Ocean();
  std::minstd_rand simple_rand;
  simple_rand.seed(128);
  for (int i = 0; i < 500; i++) {
    ocean->addObject(new Stone, simple_rand() % M, simple_rand() % N);
    ocean->addObject(new Prey, simple_rand() % M, simple_rand() % N);
    ocean->addObject(new Predator, simple_rand() % M, simple_rand() % N);
  }
  ocean->run();
}
