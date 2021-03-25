// Copyright GN 2021

#include "../include/ocean.h"

int main() {
  Ocean ocn;
  ocn.generateWorld(1000, 500, 50, 40);
  ocn.run();
  return 0;
}
