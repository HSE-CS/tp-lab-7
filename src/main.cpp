// Copyright 2020 Uskova

#include "ocean.h"

int main() {
  Ocean* ocean = new Ocean ();
  ocean->createLife();
  ocean->print();
  ocean->run();
  return 0;
}
