// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>

#include "cell.h"
#include "common.h"

class Ocean {
 private:
  Cell *cells;
  std::list<Object *> objects;
  unsigned int M;
  unsigned int N;

 public:
  explicit Ocean(int _M = 10, int _N = 10);
  ~Ocean();
  void print() const;
  void AddObjects();
  void run();
};

#endif  // INCLUDE_OCEAN_H_
