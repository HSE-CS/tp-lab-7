// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../include/common.h"
#include "../include/cell.h"
#include "../include/object.h"
#include "../include/predator.h"
#include "../include/prey.h"
#include "../include/stone.h"


class Ocean {
 public:

  void run();

  void print();
  void fullMatrix(float, float, float);
  void addObject(Object*);
  void deleteObject(Object*);

  Cell* getEmptyCellNearTo(Cell*);
  Cell* getPreyCellNearTo(Cell*);

 private:
  Cell** matrix_cell;
  std::list<Object*> objects;
};


#endif  // INCLUDE_OCEAN_H_
