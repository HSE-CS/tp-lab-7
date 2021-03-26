// Copyright 2021 Egor Buzanov

#include "../include/ocean.h"

int main() {
  unsigned int M = 0;
  unsigned int N = 0;
  std::cin >> M >> N;
  Ocean ocean(M, N);
  ocean.run();
  return 0;
}
