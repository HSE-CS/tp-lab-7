// Copyright 2021 Kuznetsov Mikhail

#include <ctime>
#include <random>
#include "ocean.h"

int main() {
  srand(time(0));
  Ocean ocean(50, 100);
  ocean.createObjects(NATURE::STONE, 200);
  ocean.createObjects(NATURE::PREY, 2000);
  ocean.createObjects(NATURE::PREDATOR, 500);
  ocean.run(1000);
  return 0;
}
