// Copyright 2021 VadMack

#include <iostream>
#include <ocean.h>
int main() {
  srand(time(0));
  Ocean ocean(10, 10, 1, 2, 3);
  //ocean.print();
  ocean.run();
}
