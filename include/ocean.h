// Copyright 2021 Pavlova D.

#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"
#include <list>

class Ocean
{

private:
  Cell **cells;
  std::list<Object*> stuff;

public:
  Ocean();
  ~Ocean();
  void print() const;
  void addObjects(...);
  void run();
};
#endif