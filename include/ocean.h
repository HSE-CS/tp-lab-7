// Copyright 2020 Uskova
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include <iostream>
#include <vector>

#include "Cell.h"
#include "common.h"
#include "stone.h"
#include "Object.h"
#include "prey.h"
#include "predator.h"

class Ocean {
 private:
  Cell **cells;
  std::list<Object *> stuff;
  std::vector<Object *> forDeleting;
 public:
  Ocean();
  ~Ocean();
  void print() const;
  void createLife();
  void addObject(Object*);
  void inDeleteList(Object *);
  void cleanDeleteList();
  Cell** getOcean();
  void run();
};

#endif  // INCLUDE_OCEAN_H_
