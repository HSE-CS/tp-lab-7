//// Copyright 2021 Ozhiganova Polina
#include "ocean.h"

int main() {
  Ocean *ocean = new Ocean();
  ocean->fullHouse();
//  float preyPerc=0.5, predatorPerc=0.08, stonePerc=0.2;
//  ocean->fullHouse(preyPerc, predatorPerc, stonePerc);
  ocean->print();
  ocean->run();
  return 0;
}
