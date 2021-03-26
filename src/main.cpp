//  Copyright 2021 GHA created by Klykov Anton

#include <iostream>

#include "Ocean.h"

int main() {
  Ocean ocean;
  ocean.CreateEmptyOcean();
  ocean.LaunchCreatures();
  ocean.printOcean();
  for (int j = 0; j < 100; ++j) {
    if (ocean.findPrey() && ocean.findPredator()) {
      for (int i = 0; i < ocean.GetCreatures().size(); ++i) {
        ocean.GetCreatures()[i]->live();
      }
      ocean.printOcean();
    } else {
      break;
    }
  }
  return 0;
}
