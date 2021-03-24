// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>

#include "common.h"
//#include "Cell.h"
#include "Prey.h"
#include "Stone.h"
#include "Predator.h"
//#include "Object.h"

class Cell;
class Object;
class Ocean {

 private:
  Cell **cells;
  std::list<Object*> stuff;
  std::list<Object*> deleteObject;

 public:
  Ocean() {
    cells = new Cell * [M];
    for (int i = 0; i < M; i++) {
      cells[i] = new Cell[M];
      for (int j = 0; j < N; j++) {
        cells[i][j].init({j, i}, this);
      }
    }
  }
  ~Ocean() {
    for (int i = 0; i < N; i++)
      delete [] cells[i];
    delete [] cells;
  }
  void print() const;
  void addObject(Object*);
  void run();
  void addToDeleteObject(Object*);
  Cell* getCell(int x, int y);
  void deleteObjectFun();
  void initOcean();
};

#endif  // INCLUDE_OCEAN_H_
