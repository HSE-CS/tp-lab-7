// Copyright 2021 Ryzhova
#include "../include/ocean.h"

int main() {
  Ocean* ocean = new Ocean;
  for (int i = 0; i < 30; i++) {
    ocean->addRandomObject();
  }
  ocean->run();
  return 0;
}
