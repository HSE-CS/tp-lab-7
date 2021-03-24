// Copyright 2021 Dumarevskaya
#include "Ocean.h"
#include <ctime>
#include <iostream>

int main() {
  srand(time(NULL));
  Ocean* ocean = new Ocean();
  ocean->run();
  return 0;
}