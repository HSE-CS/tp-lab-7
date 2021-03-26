// Copyright 26.03.21 DenisKabanov

#include <ocean.h>
#include <iostream>
int main() {
  std::cout << "Project: " << std::endl;
  Ocean ocean(30, 70, 20, 30, 20);
  ocean.run();
}
