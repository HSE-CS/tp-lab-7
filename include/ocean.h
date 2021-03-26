// Copyright DB 2021
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "../include/common.h"
#include "../include/cell.h"

#include "list"

class Ocean {
 private:
  Cell** cells;
  std::list<Object*> objects;

 public:
  Ocean();
  ~Ocean() {
    for (int i = 0; i < N; i++) {
      delete[] cells[i];
    }
    delete[] cells;
  }
  void generateWorld(int nstones, int ncorals,
                     int npreys, int npredators);
  void print() const;
  void addObject(Object*);
  void run();
  Cell* getCell(Pair);
};

#endif  // INCLUDE_OCEAN_H_
