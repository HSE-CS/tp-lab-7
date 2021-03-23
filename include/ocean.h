// Copyright 2021 Dev-will-work
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "../include/cell.h"

class Ocean {
  friend class Cell;
 private:
  Cell **cells;
  std::list<Object*> stuff;
  std::list<Object*> almostDead;

 public:
  Ocean();
  ~Ocean();
  void print() const;
  void addObjects(Object* objects = nullptr, size_t size = 0);
  void run();
  Cell** getCells();
  std::list<Object*>& getStuff();
};
#endif  // INCLUDE_OCEAN_H_
