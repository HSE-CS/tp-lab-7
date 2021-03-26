//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "Cell.h"
#include "parametr.h"
#include "Object.h"
#include "Factory.h"
#include <iostream>
#include <vector>
#include <random>
class Object;
class Cell;

class Ocean {
 private:
  std::vector<Object*> MarineCreatures;
  std::vector<std::vector<Cell* >> OceanCells;

 public:
  void CreateEmptyOcean();
  void LaunchCreatures();
  void printOcean();
  std::vector<std::vector<Cell* >> GetCells();
  void SetOceanCells(std::vector<std::vector<Cell* >>
      TemporaryCells);
  std::vector<Object*> GetCreatures();
  void SetMarineCreatures(std::vector<Object*>
      TemporaryCreatures);
  bool findPrey();
  bool findPredator();
};

#endif
