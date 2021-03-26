// Copyright 2021 Kuznetsov Mikhail

#include <ctime>
#include <random>
#include "ocean.h"

int main() {
  srand(time(0));
  Ocean ocean(20, 168);
  ocean.generateOrder();
  ocean.createObjects(NATURE::STONE, 370);
  ocean.createObjects(NATURE::PREY, 980);
  ocean.createObjects(NATURE::PREDATOR, 520);
  ocean.run(10);
  return 0;
}
