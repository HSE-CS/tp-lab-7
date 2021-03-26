// Copyright 2021 Kuznetsov Mikhail

#include <ctime>
#include "ocean.h"

int main() {
  srand(time(0));
  Ocean ocean(HEIGHT, WIDTH);
  ocean.generateOrder();
  ocean.createObjects(NATURE::STONE, NUMBEROFSTONES);
  ocean.createObjects(NATURE::PREY, NUMBEROFPREYS);
  ocean.createObjects(NATURE::PREDATOR, NUMBEROFPREDATORS);
  ocean.run(YEARS);
  return 0;
}
