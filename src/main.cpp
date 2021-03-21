// Copyright 2021 VadMack

#include <iostream>
#include <ocean.h>
int main() {
  srand(time(0));
  Ocean ocean(50, 50, 12, 90, 45);
  ocean.run();
}
