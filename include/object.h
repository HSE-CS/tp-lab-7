// Copyright 2021 Artem Danyaev
#pragma once

#include <vector>
#include "../include/ocean.h"
#include "../include/cell.h"
#include "../include/common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;

class Object {
 protected:
  ObjType type;
  Cell* cell;
  Cell* findFreeNeighbour();
  bool checkIfCellExists(Pair crd);

 public:
  explicit Object(ObjType t, Cell* c = nullptr);
  virtual void live() = 0;
  void setCell(Cell* c);
  ObjType getType();
};
