// Copyright 2021 Egor Trukhin
#include <iostream>

#include "ocean.h"

int main() {
  try {
    Ocean* mOcean = new Ocean();
    mOcean->run();
    delete mOcean;
  } catch (std::exception& error) {
    std::cerr << error.what() << std::endl;
  }
  return 0;
}
